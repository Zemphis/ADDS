#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
 public:
  virtual ~Move() = default;
  virtual std::string getMove() = 0;
  virtual bool wins(Move* move2) = 0;
};

#endif