#ifndef PAPER_H
#define PAPER_H

#include "Move.h"

class Paper : public Move {
 public:
  std::string getMove() override { return "Paper"; }
  bool wins(Move* move2) override { return move2->getMove() == "Rock"; }
};

#endif