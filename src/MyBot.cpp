#include "../include/MyBot.hpp"
#include "CommandStorage.cpp"

MyBot::MyBot(const std::string& token): token(token) {}

void MyBot::start() {
  TgBot::Bot bot{token};

  CommandsStorage commandsStorage(bot);

  for (auto& pair : *(commandsStorage.getStorage())) {
    bot.getEvents().onCommand(pair.first, pair.second);
  }

  bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    std::cout << "User wrote: " << message->text << std::endl;
    
     if (StringTools::startsWith(message->text, "/")) {
      return;
    }

    bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
  });

  signal(SIGINT, [](int s) {
    printf("SIGINT got\n");
    exit(0);
  });

  try {
    printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
    bot.getApi().deleteWebhook();

    TgBot::TgLongPoll longPoll(bot);
    while (true) {
      printf("Long poll started\n");
      longPoll.start();
    }
  } catch (std::exception& e) {
    printf("error: %s\n", e.what());
  }
}