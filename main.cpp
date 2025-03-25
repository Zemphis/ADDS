#include <iostream>
#include <sstream>

#include "EffectiveFibonacci.h"
#include "Fibonacci.h"
#include "Reverse.h"

int main() {
  std::string inputLine;
  std::getline(std::cin, inputLine);

  std::stringstream ss(inputLine);
  int i, n1, n2;
  std::string s;

  ss >> i >> s >> n1 >> n2;

  Reverse rev;
  Fibonacci fib;
  EffectiveFibonacci effFib(std::max(n1, n2) + 1);

  int reversedI = rev.reverseDigit(i);
  if (reversedI != -1) {
    std::cout << reversedI << " ";
  }

  std::cout << rev.reverseString(s) << " ";
  std::cout << fib.fibo(n1) << " ";
  std::cout << effFib.fibo(n2) << std::endl;

  return 0;
}