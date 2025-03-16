#ifndef PIRATE_H
#define PIRATE_H

#include "Move.h"

class Pirate : public Move {
 public:
  std::string getMove() override { return "Pirate"; }
  bool wins(Move* move2) override {
    return move2->getMove() == "Monkey" || move2->getMove() == "Robot";
  }
};

#endif