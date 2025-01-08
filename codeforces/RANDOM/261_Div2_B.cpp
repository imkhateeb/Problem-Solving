#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<let>
#define vvi vector<vector<let>>
#define vs vector<string>
#define vpii vector<pair<let, let>>
using namespace std;

int main()
{
  let n;
  let maxi = LLONG_MIN;
  let mini = LLONG_MAX;

  cin >> n;
  map<let, let> m;

  for (let i = 0; i < n; i++)
  {
    let x;
    cin >> x;
    m[x]++;

    maxi = max(maxi, x);
    mini = min(mini, x);
  }

  let maxDiff = maxi - mini;

  let ans = 0;
  if (maxDiff == 0)
  {
    for (auto it : m)
    {
      let count = it.second;
      ans += (count * (count - 1)) / 2;
    }
  }
  else
  {
    for (auto it : m)
    {
      let key = it.first;
      if (m.count(key + maxDiff))
      {
        ans += m[key] * m[key + maxDiff];
      }
    }
  }

  cout << maxDiff << " " << ans << endl;

  return 0;
}
