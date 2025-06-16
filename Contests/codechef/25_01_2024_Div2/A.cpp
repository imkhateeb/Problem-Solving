#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
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
    let n, x;
    cin >> n >> x;

    vi h(n);

    for (int i = 0; i < n; i++)
    {
      cin >> h[i];
    }

    sort(allr(h));

    let a = h[0];
    let inc = x;

    for (let i = 1; i < n; i++)
    {
      if (a < (h[i] + inc))
      {
        a = h[i] + inc;
      }
      inc += x;
    }

    cout << a << endl;
  }

  return 0;
}
