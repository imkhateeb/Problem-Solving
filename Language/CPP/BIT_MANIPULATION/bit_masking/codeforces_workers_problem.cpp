#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> masks(n, 0);

  for (int i = 0; i < n; ++i)
  {
    int number_of_workers;
    cin >> number_of_workers;

    // Creating every workers mask
    int mask = 0;
    for (int j = 0; j < number_of_workers; ++j)
    {
      int day;
      cin >> day;
      mask = (mask | (1 << day));
    }
    masks[i] = mask;
  }

  // Finding maximum common days b/w two worker and that two workers
  int maxCommon = 0;
  int person1 = -1;
  int person2 = -1;
  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      int intersection = (masks[i] & masks[j]);
      int common_days = __builtin_popcount(intersection);
      if (common_days > maxCommon)
      {
        maxCommon = common_days;
        person1 = i;
        person2 = j;
      }
    }
  }

  cout << person1 << " " << person2 << endl;
  cout << maxCommon << endl;
  return 0;
}