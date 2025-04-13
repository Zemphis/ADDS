#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int target) {
  return binarySearch(list, target, 0, list.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& list,
                                         int target, int left, int right) {
  if (left > right) return false;
  int mid = left + (right - left) / 2;
  if (list[mid] == target) return true;
  if (target < list[mid])
    return binarySearch(list, target, left, mid - 1);
  else
    return binarySearch(list, target, mid + 1, right);
}
