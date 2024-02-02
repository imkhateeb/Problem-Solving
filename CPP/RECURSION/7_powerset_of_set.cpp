#include <bits/stdc++.h>

using namespace std;

void powerSet(
    vector<int> nums,
    vector<int> output,
    int index,
    vector<vector<int>> &ans)
{
  if (index == nums.size())
  {
    ans.push_back(output);
    return;
  };

  // Exclude
  powerSet(nums, output, index + 1, ans);

  // Include
  output.push_back(nums[index]);
  powerSet(nums, output, index + 1, ans);
};

int main()
{
  vector<int> nums;

  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;

    nums.push_back(num);
  };

  vector<vector<int>> ans;
  vector<int> output;
  powerSet(nums, output, 0, ans);

  int p = ans.size();

  cout << endl;

  cout << "Power Set: ";
  cout << "{";
  for (int i = 0; i < p; i++)
  {
    int q = ans[i].size();
    cout << "{";
    for (int j = 0; j < q; j++)
    {
      if (j == q - 1) // last element
        cout << ans[i][j];
      else // not last element
        cout << ans[i][j] << ", ";
    }

    cout << "}"; // end of set

    if (i != p - 1) // not last set
      cout << ", ";
  }
  cout << "}";
  return 0;
}