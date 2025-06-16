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

void findMaxPieces(int n, int a, int b, int c, int pieces, int &maxi)
{
  if (n == 0)
  {
    maxi = max(maxi, pieces);
    return;
  }
  if (n < 0)
  {
    return;
  }

  findMaxPieces(n - a, a, b, c, pieces + 1, maxi);
  findMaxPieces(n - b, a, b, c, pieces + 1, maxi);
  findMaxPieces(n - c, a, b, c, pieces + 1, maxi);
}

int main()
{
  let n, a, b, c;
  cin >> n >> a >> b >> c;

  let ans = 0;

  for (let x = 0; x <= n; x++)
  {
    for (let y = 0; y <= n; y++)
    {
      let z = n - (a * x + b * y);
      if (z >= 0 && z % c == 0)
      {
        ans = max(ans, x + y + z / c);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
