#include <iostream>
#include <unordered_map>

int fib(int n) {
  static std::unordered_map<int, int> fib_values;
  std::unordered_map<int, int>::iterator it;
  std::cout << "calculating fib " << n << std::endl;
  it = fib_values.find(n);
  if (it != fib_values.end()) return it->second;
  if (n == 0 || n == 1) {
    fib_values.insert(std::pair<int, int>(n, n));
    return n;
  }
  int result = fib(n - 1) + fib(n - 2);
  fib_values.insert(std::pair<int, int>(n, result));
  return result;
}

int main(void) {
  int n;
  std::cin >> n;
  int result = fib(n);
  std::cout << result << std::endl;
  std::cin >> n;
  result = fib(n);
  std::cout << result << std::endl;
}