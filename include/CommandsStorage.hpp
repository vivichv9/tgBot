#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <boost/any.hpp>

#include <tgbot/tgbot.h>

using StoragePointer =  std::unique_ptr<std::unordered_map<std::string, TgBot::EventBroadcaster::MessageListener>>;

class CommandsStorage {
private:
  StoragePointer storage;
  TgBot::Bot& bot;

//  std::unique_ptr<TgBot::Bot> botPtr;

public: 
  CommandsStorage(TgBot::Bot& bot);
  CommandsStorage(const CommandsStorage&) = delete;
  CommandsStorage operator=(const CommandsStorage&) = delete;

  void addCommand(const std::string& key, const TgBot::EventBroadcaster::MessageListener& val);
  void deleteCommand(const std::string& key);
  const StoragePointer& getStorage() const;
};
