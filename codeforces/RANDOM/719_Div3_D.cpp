#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{
  let t;
  cin >> t;

  while (t--)
  {
    let n;
    cin >> n;

    unordered_map<let, let> mp;

    for (let i = 0; i < n; i++)
    {
      let x;
      cin >> x;
      mp[x - i]++;
    }

    let ans = 0;
    for (auto it : mp)
    {
      ans += (it.second * (it.second - 1)) / 2;
    }

    cout << ans << endl;
  }

  return 0;
}
