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
  let n, k;
  cin >> n >> k;
  vi v(n);

  for (let i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  let x = v[k - 1];

  if (k == 0)
  {
    if (v[0] == 1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << 1 << endl;
    }
    return 0;
  }

  if (k < n && v[k] <= x)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << x << endl;
  }

  return 0;
}