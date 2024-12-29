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
  let t;
  cin >> t;

  while (t--)
  {
    let n;
    cin >> n;

    vi v(n);

    for (let i = 0; i < n; i++)
    {
      cin >> v[i];
    }

    if (n == 1)
    {
      cout << v[0] << endl;
      continue;
    }

    let ans = 0;
    let curr = INT_MIN;

    for (let i = 0; i < n - 1; i++)
    {
      if (v[i] * v[i + 1] > 0)
      {
        curr = max(curr, v[i]);
      }
      else
      {
        ans += max(curr, v[i]);
        curr = INT_MIN;
      }
    }

    if (v[n - 1] * v[n - 2] > 0)
    {
      ans += max(curr, v[n - 1]);
    }
    else
    {
      ans += v[n - 1];
    }

    cout << ans << endl;
  }

  return 0;
}