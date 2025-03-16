#include "Referee.h"

Referee::Referee() {}

Referee::~Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
  Move* p1 = player1->makeMove();
  Move* p2 = player2->makeMove();

  Player* winner = nullptr;

  if (p1->wins(p2)) {
    winner = player1;
  } else {
    winner = player2;
  }
  delete p1;
  delete p2;
  return winner;
}
