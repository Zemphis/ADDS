#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H

#include <unordered_map>

class EfficientTruckloads {
 private:
  std::unordered_map<int, int> a;

 public:
  int numTrucks(int numCrates, int loadSize);
};

#endif
