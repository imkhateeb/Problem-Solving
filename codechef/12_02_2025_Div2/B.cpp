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
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    vi a(n);
    unordered_map<let, let> m;
    let ans = -1;
    for (let i = 0; i < n; i++)
    {
      let x;
      cin >> x;
      if (m.find(x) == m.end())
      {
        m[x] = 1;
      }
      else
      {
        ans = x;
      }
    }

    if (ans == -1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << 1 << endl;
      cout << ans << endl;
    }
  }

  return 0;
}