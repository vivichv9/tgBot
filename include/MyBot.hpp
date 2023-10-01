#pragma once

#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include "CommandsStorage.hpp"

#include <tgbot/tgbot.h>


class MyBot {
private:  
  std::string token;

public:
  MyBot(const std::string& token);

  void start();
};
