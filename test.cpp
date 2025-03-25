#include <iostream>

int factorial_tail(int n, int acc) {
  if (n == 0) {
    return acc;
  } else {
    std::cout << n << " " << acc << " " << n * acc << std::endl;
    return factorial_tail(n - 1, n * acc);
  }
}

int factorial(int n) { return factorial_tail(n, 1); }

int main() {
  std::cout << factorial(5);
  return 0;
}