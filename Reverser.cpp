#include "Reverser.h"

#include <string>

int Reverser::reverseDigit(int value) {
  if (value < 0) {
    return -1;
  }
  if (value < 10) {
    return value;
  }

  int lastDigit = value % 10;
  int remaining = value / 10;

  int power = 1;
  int temp = remaining;
  while (temp > 0) {
    power *= 10;
    temp /= 10;
  }

  return lastDigit * power + reverseDigit(remaining);
}

std::string Reverser::reverseString(const std::string& characters) {
  if (characters.empty()) {
    return "ERROR";
  }
  if (characters.length() == 1) {
    return characters;
  }

  return characters.back() +
         reverseString(characters.substr(0, characters.length() - 1));
}
