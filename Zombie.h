#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
 public:
  std::string getName() override { return "Zombie"; }
  bool wins(Move* move2) override {
    return move2->getName() == "Pirate" || move2->getName() == "Monkey";
  }
};

#endif