#ifndef MONKEY_H
#define MONKEY_H

#include "Move.h"

class Monkey : public Move {
 public:
  std::string getMove() override { return "Monkey"; }
  bool wins(Move* move2) override {
    return move2->getMove() == "Ninja" || move2->getMove() == "Robot";
  }
};

#endif