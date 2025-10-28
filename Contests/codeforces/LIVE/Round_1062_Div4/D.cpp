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

let gcd(let a, let b)
{
  while (b)
  {
    let temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    vi a(n);
    for (let i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    let g = a[0];
    for (let i = 1; i < n; i++)
    {
      g = gcd(g, a[i]);
      if (g == 1)
        break;
    }

    if (g == 1)
    {
      cout << 2 << endl;
      continue;
    }

    let ans = -1;
    for (let x = 2; x <= 1000000; x++)
    {
      if (gcd(g, x) == 1)
      {
        ans = x;
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}