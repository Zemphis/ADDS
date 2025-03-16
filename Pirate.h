#ifndef PIRATE_H
#define PIRATE_H

#include "Move.h"

class Pirate : public Move {
 public:
  std::string getName() override { return "Pirate"; }
  bool wins(Move* move2) override {
    return move2->getName() == "Monkey" || move2->getName() == "Robot";
  }
};

#endif