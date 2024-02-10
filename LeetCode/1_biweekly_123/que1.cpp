#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

long long maxSubArray(vector<int> nums, int index, int k, vector<long long> &dp)
{
  if (index >= nums.size())
    return 0;
  if (dp[index] != -1)
    return dp[index];

  long long sum = 0;
  long long maxSum = INT_MIN;
  for (int i = index; i < nums.size(); i++)
  {
    if (k == abs(nums[index] - nums[i]))
    {
      sum = 0;
      for (int j = index; j <= i; j++)
      {
        sum += nums[j];
      }
      maxSum = max(maxSum, sum + maxSubArray(nums, i + 1, k, dp));
    }
  }
  return dp[index] = maxSum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int k;
  cin >> k;
  vector<long long> dp(n, -1);
  cout << maxSubArray(nums, 0, k, dp) << endl;
  return 0;
}
