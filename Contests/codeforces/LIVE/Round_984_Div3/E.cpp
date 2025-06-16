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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  let n, k, q;
  cin >> n >> k >> q;

  vvi a(n, vi(k));
  for (let i = 0; i < n; i++)
  {
    for (let j = 0; j < k; j++)
    {
      cin >> a[i][j];
    }
  }

  vvi b(n, vi(k));
  for (let j = 0; j < k; j++)
  {
    let current_or = 0;
    for (let i = 0; i < n; i++)
    {
      current_or |= a[i][j];
      b[i][j] = current_or;
    }
  }

  while (q--)
  {
    let m;
    cin >> m;
    vector<pair<let, char>> conditions(m);
    vi regions(m);

    for (let i = 0; i < m; i++)
    {
      let r;
      char o;
      let c;
      cin >> r >> o >> c;
      r--;
      regions[i] = r;
      conditions[i] = {c, o};
    }

    let ans = -1;
    for (let country = 0; country < n; country++)
    {
      bool valid = true;

      for (let i = 0; i < m && valid; i++)
      {
        let r = regions[i];
        let c = conditions[i].first;
        char o = conditions[i].second;

        if (o == '<')
        {
          if (b[country][r] >= c)
            valid = false;
        }
        else
        {
          if (b[country][r] <= c)
            valid = false;
        }
      }

      if (valid)
      {
        ans = country + 1;
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}