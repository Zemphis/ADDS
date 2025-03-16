#ifndef ROCK_H
#define ROCK_H

#include "Move.h"

class Rock : public Move {
 public:
  std::string getMove() override { return "Rock"; }
  bool wins(Move* move2) override { return move2->getMove() == "Scissors"; }
};

#endif