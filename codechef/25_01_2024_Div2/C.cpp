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
    let sum = 0;

    vi a(n);

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    sort(all(a));

    for (let i = 0; i < n; i++)
    {
      sum += a[i];
      if (sum <= ((i + 1) * (i + 1)))
      {
        sum = ((i + 1) * (i + 1));
      }
    }

    cout << sum << endl;
  }

  return 0;
}
