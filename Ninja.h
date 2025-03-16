#ifndef NINA_H
#define NINJA_H

#include "Move.h"

class Ninja : public Move {
 public:
  std::string getMove() override { return "Ninja"; }
  bool wins(Move* move2) override {
    return move2->getMove() == "Pirate" || move2->getMove() == "Zombie";
  }
};

#endif