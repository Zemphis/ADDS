#include "Human.h"

Human::Human(std::string name) : name(name) {}

Move* Human::makeMove() {
std:
  std::string move;
  std::cout << "Enter move: ";
  std::cin >> move;

  if (move == "Rock") {
    return new Rock();
  }
  if (move == "Scissors") {
    return new Scissors();
  }
  if (move == "Paper") {
    return new Paper();
  }
  if (move == "Ninja") {
    return new Ninja();
  }
  if (move == "Robot") {
    return new Robot();
  }
  if (move == "Monkey") {
    return new Monkey();
  }
  if (move == "Pirate") {
    return new Pirate();
  }
  if (move == "Zombie") {
    return new Zombie();
  } else {
    std::cout << "Invalid, defaulting to rock." << std::endl;
    return new Rock();
  }
}

std::string Human::getName() { return name; }
