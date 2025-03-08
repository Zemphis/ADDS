#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
 protected:
  std::string name;

 public:
  Player();
  virtual ~Player();

  virtual char makeMove();
  virtual std::string getName();
};

#endif