#include "Referee.h"

Referee::Referee() {}

Referee::~Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
  char p1 = player1->makeMove();
  char p2 = player2->makeMove();

  if (p1 == p2) {
    return nullptr;
  }
  if ((p1 == 'R' && p2 == 'S') || (p1 == 'S' && p2 == 'P') ||
      (p1 == 'P' && p2 == 'R')) {
    return player1;
  }
  return player2;
}
