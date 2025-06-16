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
  let n;
  cin >> n;

  vi v(n);

  vector<let> ps1(n + 1, 0);

  for (let i = 1; i <= n; i++)
  {
    let x;
    cin >> x;
    ps1[i] = ps1[i - 1] + x;
    v[i - 1] = x;
  }

  sort(v.begin(), v.end());

  vector<let> ps2(n + 1, 0);

  for (let i = 1; i <= n; i++)
  {
    ps2[i] = ps2[i - 1] + v[i - 1];
  }

  let m;
  cin >> m;

  while (m--)
  {
    let t, l, r;
    cin >> t >> l >> r;

    if (t == 1)
    {
      cout << ps1[r] - ps1[l - 1] << endl;
    }
    else
    {
      cout << ps2[r] - ps2[l - 1] << endl;
    }
  }

  return 0;
}