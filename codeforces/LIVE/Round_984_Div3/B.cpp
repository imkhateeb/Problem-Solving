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
    let n, k;
    cin >> n >> k;

    map<let, let> m;

    for (let i = 0; i < k; i++)
    {
      let x, y;
      cin >> x >> y;
      if (m.count(x))
      {
        m[x] += y;
      }
      else
      {
        m[x] = y;
      }
    }

    vector<let> v;

    for (auto i : m)
    {
      v.pb(i.ss);
    }

    sort(v.rbegin(), v.rend());
    let ans = 0;
    let m_size = v.size();
    for (let i = 0; i < min(n, m_size); i++)
    {
      ans += v[i];
    }

    cout << ans << endl;
  }

  return 0;
}
