#include <iostream>

#include "Referee.h"

Player* Referee::refGame(Player* player1, Player* player2) {
  Move* p1Move = player1->makeMove();
  Move* p2Move = player2->makeMove();

  std::cout << player1->getName() << " played " << p1Move->getMove() << "\n";
  std::cout << player2->getName() << " played " << p2Move->getMove() << "\n";

  Player* winner = nullptr;

  if (p1Move->getMove() == p2Move->getMove()) {
    std::cout << "It's a tie!\n";
  } else if (p1Move->wins(p2Move)) {
    winner = player1;
  } else {
    winner = player2;
  }

  if (winner) {
    std::cout << winner->getName() << " wins!\n";
  }

  delete p1Move;
  delete p2Move;
  return winner;
}
