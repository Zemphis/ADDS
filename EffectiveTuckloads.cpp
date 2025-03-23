#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
  if (numCrates <= loadSize) {
    return 1;
  }

  if (a.find(numCrates) != a.end()) {
    return a[numCrates];
  }

  int left = numCrates / 2;
  int right = numCrates - left;

  int result = numTrucks(left, loadSize) + numTrucks(right, loadSize);
  a[numCrates] = result;
  return result;
}
