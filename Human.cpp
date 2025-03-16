#include "Human.h"

#include <iostream>

Human::Human(std::string name) : name(name) {}
Human::~Human() {}

Move* Human::makeMove() {
  std::string move;
  std::cout << "Enter move: ";
  std::cin >> move;

  if (move == "Rock") {
    return new Rock();
  } else if (move == "Scissors") {
    return new Scissors();
  } else if (move == "Paper") {
    return new Paper();
  } else if (move == "Ninja") {
    return new Ninja();
  } else if (move == "Robot") {
    return new Robot();
  } else if (move == "Monkey") {
    return new Monkey();
  } else if (move == "Pirate") {
    return new Pirate();
  } else if (move == "Zombie") {
    return new Zombie();
  } else {
    std::cout << "Invalid, playing rock." << std::endl;
    return new Rock();
  }
}

std::string Human::getName() const { return name; }
