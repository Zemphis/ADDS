#ifndef ROBOT_H
#define ROBOT_H

#include "Move.h"

class Robot : public Move {
 public:
  std::string getName() override { return "Robot"; }
  bool wins(Move* move2) override {
    return move2->getName() == "Ninja" || move2->getName() == "Zombie";
  }
};

#endif