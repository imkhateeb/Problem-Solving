#include <iostream>
#include <set>

int main()
{
  std::set<int> s;

  // Insertion: O(log N)
  s.insert(5); // Insert 5
  s.insert(1); // Insert 1
  s.insert(3); // Insert 3

  // Access the smallest element (first element): O(1)
  std::cout << "Smallest element: " << *s.begin() << std::endl;

  // Search/Find: O(log N)
  if (s.find(3) != s.end())
  {
    std::cout << "3 is found in the set." << std::endl;
  }
  else
  {
    std::cout << "3 is not found in the set." << std::endl;
  }

  // Erase an element: O(log N)
  s.erase(3); // Remove 3 from the set
  std::cout << "3 is erased from the set." << std::endl;

  // Check existence using count (Equivalent to find): O(log N)
  if (s.count(3))
  {
    std::cout << "3 still exists in the set." << std::endl;
  }
  else
  {
    std::cout << "3 no longer exists in the set." << std::endl;
  }

  // Size of the set: O(1)
  std::cout << "Size of the set: " << s.size() << std::endl;

  // Lower bound: O(log N)
  auto it = s.lower_bound(2);
  if (it != s.end())
  {
    std::cout << "Lower bound of 2: " << *it << std::endl;
  }
  else
  {
    std::cout << "No lower bound found for 2" << std::endl;
  }

  // Upper bound: O(log N)
  it = s.upper_bound(2);
  if (it != s.end())
  {
    std::cout << "Upper bound of 2: " << *it << std::endl;
  }
  else
  {
    std::cout << "No upper bound found for 2" << std::endl;
  }

  // Clear the set: O(N)
  s.clear();
  std::cout << "Set cleared. Size after clearing: " << s.size() << std::endl;

  // Check if the set is empty: O(1)
  if (s.empty())
  {
    std::cout << "The set is empty." << std::endl;
  }

  return 0;
}
