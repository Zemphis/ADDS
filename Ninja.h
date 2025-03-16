#ifndef NINA_H
#define NINJA_H

#include "Move.h"

class Ninja : public Move {
 public:
  std::string getName() override { return "Ninja"; }
  bool wins(Move* move2) override {
    return move2->getName() == "Pirate" || move2->getName() == "Zombie";
  }
};

#endif