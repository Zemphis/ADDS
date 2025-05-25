#include <queue>
#include <vector>

int kthLargest(const std::vector<int>& nums, int k) {
  // Create a min-heap using a priority queue
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  // Insert the first k elements into the min-heap
  for (int i = 0; i < k; ++i) {
    minHeap.push(nums[i]);
  }

  // Process the remaining elements
  for (int i = k; i < nums.size(); ++i) {
    if (nums[i] > minHeap.top()) {
      minHeap.pop();
      minHeap.push(nums[i]);
    }
  }

  // The top of the min-heap is the kth largest element
  return minHeap.top();
}