#include "Fibonacci.h"

Fibonacci::Fibonacci() {}

Fibonacci::~Fibonacci() {}

int Fibonacci::fibo(int n) {
  if (n < 0) {
    std::cout << "ERROR";
    return -1;
  }
  if (n <= 1) {
    return n;
  } else {
    return fibo(n - 1) + fibo(n - 2);
  }
}
