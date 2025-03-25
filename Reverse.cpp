#include "Reverse.h"

Reverse::Reverse() {}

Reverse::~Reverse() {}

int Reverse::reverseDigit(int value) {
  if (value < 0) {
    std::cout << "ERROR";
    return -1;
  }
  if (value < 10) {
    // std::cout << value << std::endl;
    return value;
  } else {
    int lastDigit = value % 10;
    int remainingDigits = value / 10;

    int mult = 1;
    int temp = remainingDigits;
    while (temp > 0) {
      mult *= 10;
      temp /= 10;
    }

    // std::cout << lastDigit << " * " << mult << std::endl;
    return lastDigit * mult + reverseDigit(remainingDigits);
  }
}

std::string Reverse::reverseString(std::string letters) {
  if (letters.length() <= 1) {
    // std::cout << letters << std::endl;
    return letters;
  } else {
    char first = letters[0];
    std::string restOfString = letters.substr(1);
    // std::cout << first << " " << restOfString << std::endl;
    return reverseString(restOfString) + first;
  }
}