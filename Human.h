#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>

#include "Player.h"

class Human : public Player {
 private:
  std::string name;

 public:
  Human(std::string name = "Human");
  Human(std::string playerName) : name(playerName) {}

  Move* makeMove() override;
  std::string getName() override;
};

#endif
