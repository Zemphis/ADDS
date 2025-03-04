#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : private Player {
 public:
  Human(std::string name = "Human");
  char makeMove() override;
};

#endif