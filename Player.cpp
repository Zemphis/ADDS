#include "Player.h"

Player::Player() : move(" ") {}
Player::~Player() {}

char Player::makeMove() { return move; }

std::string Player::getName() { return name; }