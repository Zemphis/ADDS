#include "QuickSort.h"

#include <algorithm>

std::vector<int> QuickSort::sort(std::vector<int> list) {
  quickSort(list, 0, list.size() - 1);
  return list;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high) {
  if (low < high) {
    int pi = part(list, low, high);
    quickSort(list, low, pi - 1);
    quickSort(list, pi + 1, high);
  }
}

int QuickSort::part(std::vector<int>& list, int low, int high) {
  int index = (high - low >= 2) ? low + 2 : high;
  int pivot = list[index];
  std::swap(list[index], list[high]);

  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (list[j] < pivot) {
      i++;
      std::swap(list[i], list[j]);
    }
  }
  std::swap(list[i + 1], list[high]);
  return i + 1;
}
