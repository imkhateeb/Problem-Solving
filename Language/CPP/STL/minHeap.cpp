#include <iostream>
#include <queue>
#include <vector>

int main()
{
  // MinHeap using priority_queue with custom comparator (greater<int>)
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  // Insert elements into the MinHeap
  minHeap.push(3);
  minHeap.push(2);
  minHeap.push(15);
  minHeap.push(5);
  minHeap.push(4);
  minHeap.push(45);

  // Get the smallest element
  std::cout << "Min element: " << minHeap.top() << std::endl;

  // Remove the smallest element (extractMin)
  minHeap.pop();
  std::cout << "Min element after extraction: " << minHeap.top() << std::endl;

  // Extract all elements
  std::cout << "Extracting all elements from MinHeap: ";
  while (!minHeap.empty())
  {
    std::cout << minHeap.top() << " ";
    minHeap.pop();
  }

  return 0;
}
