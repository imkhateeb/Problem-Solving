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
    string s;
    cin >> s;
    let n = s.length();
    let q;
    cin >> q;

    set<let> pos1100;

    for (let i = 0; i <= n - 4; i++)
    {
      if (s.substr(i, 4) == "1100")
      {
        pos1100.insert(i);
      }
    }

    while (q--)
    {
      let i, v;
      cin >> i >> v;
      i--;

      s[i] = v + '0';

      for (let j = max(0LL, i - 3); j <= min(n - 4, i); j++)
      {
        if (s.substr(j, 4) == "1100")
        {
          pos1100.insert(j);
        }
        else
        {
          pos1100.erase(j);
        }
      }

      if (pos1100.empty())
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }

  return 0;
}
