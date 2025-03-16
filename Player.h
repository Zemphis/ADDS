#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Monkey.h"
#include "Move.h"
#include "Ninja.h"
#include "Paper.h"
#include "Pirate.h"
#include "Robot.h"
#include "Rock.h"
#include "Scissors.h"
#include "Zombie.h"

class Player {
 public:
  virtual Move* makeMove() = 0;
  virtual std::string getName() const = 0;
  Player();
  virtual ~Player();
};

#endif
