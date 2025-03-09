#include "Human.h"

Human::Human(std::string name) : name(name) {}

char Human::makeMove() {
  char move;
  std::cout << "Enter move: ";
  std::cin >> move;
  return move;
}

std::string Human::getName() { return name; }
