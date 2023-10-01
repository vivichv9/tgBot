#include "../include/MyBot.hpp"
#include "MyBot.cpp"

int main() {
  std::ifstream file("config/token");

  if (!file) {
    std::cerr << "File open error!" << std::endl;
    exit(-1);
  }

  std::string token;
  file >> token;
  MyBot bot{token};
  bot.start();

  return 0;
}