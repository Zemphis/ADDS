#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
 public:
  std::string getMove() override { return "Zombie"; }
  bool wins(Move* move2) override {
    return move2->getMove() == "Pirate" || move2->getMove() == "Monkey";
  }
};

#endif