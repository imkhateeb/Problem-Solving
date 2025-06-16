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
    vvi a(n + 1, vi(n + 1));

    for (let i = 1; i <= n; i++)
      for (let j = 1; j <= n; j++)
        cin >> a[i][j];

    let ans = 0;

    for (let col = n; col >= 1; col--)
    {
      let min_neg = 0;

      for (let i = 1, j = col; i <= n && j <= n; i++, j++)
      {
        min_neg = min(min_neg, a[i][j]);
      }

      ans += abs(min_neg);
    }

    for (let row = 2; row <= n; row++)
    {
      let min_neg = 0;

      for (let i = row, j = 1; i <= n && j <= n; i++, j++)
      {
        min_neg = min(min_neg, a[i][j]);
      }

      ans += abs(min_neg);
    }

    cout << ans << endl;
  }

  return 0;
}
