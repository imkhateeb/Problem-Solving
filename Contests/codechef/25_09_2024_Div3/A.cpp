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
    let x, y, z;
    cin >> x >> y >> z;

    if ((y - x) != (z - y))
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }

  return 0;
}