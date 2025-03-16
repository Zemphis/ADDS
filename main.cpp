#include <iostream>

#include "Human.h"
#include "Referee.h"

int main() {
  Player* player1 = new Human("a");
  Player* player2 = new Human("b");

  Referee referee;
  Player* winner = referee.refGame(player1, player2);

  if (winner) {
    std::cout << "Winner: " << winner->getName() << std::endl;
  } else {
    std::cout << "Tie\n";
  }

  delete player1;
  delete player2;

  return 0;
}
