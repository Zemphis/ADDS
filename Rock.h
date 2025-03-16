#ifndef ROCK_H
#define ROCK_H

#include "Move.h"

class Rock : public Move {
 public:
  std::string getName() override { return "Rock"; }
  bool wins(Move* move2) override { return move2->getName() == "Scissors"; }
};

#endif