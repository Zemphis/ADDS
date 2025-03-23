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

  int pow = 1;
  while (remaining > 0) {
    pow *= 10;
    remaining /= 10;
  }

  return lastDigit * pow + reverseDigit(remaining);
}

std::string Reverser::reverseString(const std::string& chars) {
  if (chars.empty()) {
    return "ERROR";
  }
  if (chars.length() == 1) {
    return chars;
  }

  return chars.back() + reverseString(chars.substr(0, chars.length() - 1));
}
