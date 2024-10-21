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
    int n;
    cin >> n;

    vector<pair<let, pair<let, let>>> v;

    for (int i = 0; i < n; i++)
    {
      let x, y;
      cin >> x >> y;
      v.pb({(x + y) / 2, {x, y}});
    }

    sort(all(v));

    for (auto it = v.begin(); it != v.end(); it++)
    {
      cout << it->second.ff << " " << it->second.ss << " ";
    }
    cout << endl;
  }

  return 0;
}
