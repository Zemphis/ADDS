#ifndef EFFECTIVEFIBONACCI_H
#define EFFECTIVEFIBONACCI_H

#include <iostream>
#include <vector>

class EffectiveFibonacci {
 private:
  std::vector<int> map;

 public:
  EffectiveFibonacci();
  EffectiveFibonacci(int max);
  ~EffectiveFibonacci();

  int fibo(int n);
};

#endif