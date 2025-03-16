#ifndef ROBOT_H
#define ROBOT_H

#include "Move.h"

class Robot : public Move {
 public:
  std::string getMove() override { return "Robot"; }
  bool wins(Move* move2) override {
    return move2->getMove() == "Ninja" || move2->getMove() == "Zombie";
  }
};

#endif