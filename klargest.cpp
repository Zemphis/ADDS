#include <queue>
#include <vector>

int kth_largest(std::vector<int> nums, int k) {
  // Create a min-heap using a priority queue
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  // Insert the first k elements into the min-heap
  for (int val : nums) {
    minHeap.push(val);
    // If the size of the heap exceeds k, remove the smallest element
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  // The top of the min-heap is the kth largest element
  return minHeap.top();
}