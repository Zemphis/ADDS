#include "Human.h"
Human::Human(std::string name) { this->name = name; }

char Human::makeMove() {
  std::cout << "Enter move: ";
  char move;
  std::cin >> move;
  return toupper(move);
}

std::string Human::getName() { return name; }