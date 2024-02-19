#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int> &nums)
{
  int candidate = nums[0];
  int count = 1;

  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] == candidate)
    {
      count++;
    }
    else
    {
      count--;
      if (count == 0)
      {
        candidate = nums[i];
        count = 1;
      }
    }
  }

  // At this point, candidate may or may not be the majority element.
  // We need to verify if it occurs more than n/2 times.
  count = 0;
  for (int num : nums)
  {
    if (num == candidate)
    {
      count++;
    }
  }

  if (count > nums.size() / 2)
  {
    return candidate;
  }
  else
  {
    return -1; // No majority element found
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    vector<int> nums;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      nums.push_back(num);
    }
    int majorityElement = findMajorityElement(nums);
    if (majorityElement != -1)
    {
      cout << "The majority element is: " << majorityElement << endl;
    }
    else
    {
      cout << "No majority element found" << endl;
    }
  }
  return 0;
}