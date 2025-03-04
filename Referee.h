#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"

class Referee {
 public:
  Referee();
  ~Referee();

  Player* game(Player* player1, Player* player2);
};

#endif