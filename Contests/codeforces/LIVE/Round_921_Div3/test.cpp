#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasModuloOnePair(const vector<int> &nums)
{
  unordered_set<int> remainders;

  for (int num : nums)
  {
    int remainder = num % 1;                    // Calculate remainder when divided by 1
    int inverseRemainder = (1 - remainder) % 1; // Calculate the inverse remainder

    // If the set already contains the inverse remainder, a pair with modulo 1 exists
    if (remainders.find(inverseRemainder) != remainders.end())
    {
      return true;
    }

    // Insert the current remainder into the set
    remainders.insert(remainder);
  }

  // If no such pair is found after iterating through all elements
  return false;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> nums[i];
  }

  bool result = hasModuloOnePair(nums);
  if (result)
  {
    cout << "Yes, a pair with modulo 1 exists." << endl;
  }
  else
  {
    cout << "No, no pair with modulo 1 exists." << endl;
  }
  return 0;
}
