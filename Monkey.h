#ifndef MONKEY_H
#define MONKEY_H

#include "Move.h"

class Monkey : public Move {
 public:
  std::string getName() override { return "Monkey"; }
  bool wins(Move* move2) override {
    return move2->getName() == "Ninja" || move2->getName() == "Robot";
  }
};

#endif