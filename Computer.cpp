#include "Computer.h"

Computer::Computer() {}
Computer::~Computer() {}

Move* Computer::makeMove() { return new Rock(); }

std::string Computer::getName() const { return "Computer"; }
