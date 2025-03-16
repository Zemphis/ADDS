#ifndef SCISSORS_H
#define SCISSORS_H

#include "Move.h"

class Scissors : public Move {
 public:
  std::string getMove() override { return "Scissors"; }
  bool wins(Move* move2) override { return move2->getMove() == "Paper"; }
};

#endif