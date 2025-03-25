#include <math.h>

#include <iostream>

int recursiveSum(int n) {
  if (n <= 1) {
    std::cout << n << std::endl;
    return n;
  } else {
    std::cout << n << std::endl;
    return n + recursiveSum(n - 1);
  }
}

int evenSquares(int n) {
  if (n == 0) {
    std::cout << n << std::endl;
    return n;
  } else if (n % 2 == 0) {
    std::cout << "Even so square " << n << std::endl;
    return (n * n) + evenSquares(n - 1);
  } else {
    std::cout << "Not even " << n << std::endl;
    return evenSquares(n - 1);
  }
}

int doubleSquares(int n) {
  if (n == 0) {
    return n;
  } else {
    std::cout << n << std::endl;
    return pow(n + n, 2) + doubleSquares(n - 1);
  }
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    std::cout << n << std::endl;
    return n * factorial(n - 1);
  }
}

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  std::cout << fibonacci(7) << std::endl;
  return 0;
}
