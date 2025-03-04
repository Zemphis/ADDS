#include "Referee.h"

Referee::Referee() {}

Referee::~Referee() {}

Player* Referee::game(Player* player1, Player* player2) {
  char p1 = player1->makeMove();
  char p2 = player2->makeMove();

  if (p1 == p2) {
    return nullptr;
  }
  if ((move1 == 'R' && move2 == 'S') || (move1 == 'S' && move2 == 'P') ||
      (move1 == 'P' && move2 == 'R')) {
    return player1;
  } else {
    return player2;
  }
};