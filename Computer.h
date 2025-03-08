#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : private Player {
 public:
  Computer(std::string name = "Computer");
  char makeMove() override;
};

#endif