#include <iostream>
#include <sstream>
#include <vector>

#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
  std::string line;
  std::getline(std::cin, line);

  std::istringstream iss(line);
  std::vector<int> input;
  int number;
  while (iss >> number) {
    input.push_back(number);
  }

  QuickSort qs;
  std::vector<int> sorted = qs.sort(input);

  RecursiveBinarySearch rbs;
  bool found = rbs.search(sorted, 1);

  std::cout << (found ? "true" : "false");
  for (int n : sorted) {
    std::cout << " " << n;
  }
  std::cout << std::endl;

  return 0;
}
