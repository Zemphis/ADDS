#include "Truckloads.h"

int Truckloads::truckNum(int crateNum, int loadSize) {
  if (crateNum <= loadSize) {
    return 1;
  }

  int left = crateNum / 2;
  int right = crateNum - left;

  return truckNum(left, loadSize) + truckNum(right, loadSize);
}
