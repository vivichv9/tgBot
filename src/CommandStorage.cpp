#include "../include/CommandsStorage.hpp"

CommandsStorage::CommandsStorage(TgBot::Bot& bot): bot(bot) {
  storage = std::make_unique<std::unordered_map<std::string, TgBot::EventBroadcaster::MessageListener>>();
  auto func = [&bot](TgBot::Message::Ptr message) {

    bot.getApi().sendMessage(message->chat->id, "Hi!");
  };

  storage->insert(std::make_pair("start", func));
}

void CommandsStorage::addCommand(const std::string& key, const TgBot::EventBroadcaster::MessageListener& val) {
  storage->insert(std::make_pair(key, val));
}

void CommandsStorage::deleteCommand(const std::string& key) {
  storage->erase(key);
}

const StoragePointer& CommandsStorage::getStorage() const {
  return storage;
}