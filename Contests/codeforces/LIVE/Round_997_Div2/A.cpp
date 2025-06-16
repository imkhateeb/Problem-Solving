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
    let n, m;
    cin >> n >> m;

    int f, s;
    cin >> f >> s;
    int l = m;
    int b = m;

    for (int i = 1; i < n; i++)
    {
      let x, y;
      cin >> x >> y;
      b += x;
      l += y;
    }

    cout << 2 * (l + b) << endl;
  }

  return 0;
}
