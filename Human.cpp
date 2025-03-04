#include "Human.h"
Human::Human(std::string name) { this->name = name; }

char Human::makeMove() {
  std::cout << "Enter move: ";
  std::cin >> move;
  return toupper(move);
}