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
    int n, m, p;
    cin >> n >> m >> p;

    int b1, b2;
    cin >> b1 >> b2;

    int q;
    cin >> q;

    if (q >= min(b1, b2) && q <= max(b1, b2))
    {
      cout << (max(b1, b2) - min(b1, b2)) / 2 << endl;
    }
    else
    {
      if (q > max(b1, b2))
      {
        cout << (n - max(b1, b2)) << endl;
      }
      else
      {
        cout << (min(b1, b2) - 1) << endl;
      }
    }
  }

  return 0;
}