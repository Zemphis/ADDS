#include "EffectiveFibonacci.h"

EffectiveFibonacci::EffectiveFibonacci() : map(100, -1) {}

EffectiveFibonacci::EffectiveFibonacci(int max) : map(max, -1) {}

EffectiveFibonacci::~EffectiveFibonacci() {}

int EffectiveFibonacci::fibo(int n) {
  if (n < 0) {
    std::cout << "ERROR";
    return -1;
  }
  if (n <= 1) {
    return n;
  }
  if (map[n] != -1) {
    return map[n];
  }
  map[n] = fibo(n - 1) + fibo(n - 2);
  return map[n];
}