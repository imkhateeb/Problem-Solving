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
  cin >> n;
  vi v(n);
  let totalOnes = 0;

  for (let i = 0; i < n; i++)
  {
    cin >> v[i];
    totalOnes += v[i] & 1;
  }

  if (totalOnes == n)
  {
    cout << n - 1 << endl;
    return 0;
  }

  let ans = 0;

  let z = 0;
  let o = 0;

  for (let i = 0; i < n; i++)
  {
    if (v[i] == 0)
    {
      z++;
    }
    else
    {
      o++;
    }

    if (z - o > 0)
    {
      if (ans < z - o)
      {
        ans = z - o;
      }
    }
    else
    {
      z = 0;
      o = 0;
    }
  }

  cout << ans + totalOnes << endl;

  return 0;
}