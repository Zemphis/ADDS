#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int crateNum, int loadSize) {
  if (crateNum <= loadSize) {
    return 1;
  }

  if (a.find(crateNum) != a.end()) {
    return a[crateNum];
  }

  int left = crateNum / 2;
  int right = crateNum - left;

  int result = numTrucks(left, loadSize) + numTrucks(right, loadSize);
  a[crateNum] = result;
  return result;
}
