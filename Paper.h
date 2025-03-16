#ifndef PAPER_H
#define PAPER_H

#include "Move.h"

class Paper : public Move {
 public:
  std::string getName() override { return "Paper"; }
  bool wins(Move* move2) override { return move2->getName() == "Rock"; }
};

#endif