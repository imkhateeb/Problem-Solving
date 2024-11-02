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

let countPattern(vector<let> &layer)
{
  let count = 0;
  let n = layer.size();

  for (let i = 0; i < n; i++)
  {
    if (i + 3 < n &&
        layer[i] == 1 &&
        layer[i + 1] == 5 &&
        layer[i + 2] == 4 &&
        layer[i + 3] == 3)
    {
      count++;
    }
  }

  for (let i = 0; i < 3; i++)
  {
    let pos = n - 3 + i;
    if (layer[pos] == 1 &&
        layer[(pos + 1) % n] == 5 &&
        layer[(pos + 2) % n] == 4 &&
        layer[(pos + 3) % n] == 3)
    {
      count++;
    }
  }

  return count;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n, m;
    cin >> n >> m;

    vector<vector<let>> a(n, vector<let>(m));

    for (let i = 0; i < n; i++)
    {
      for (let j = 0; j < m; j++)
      {
        char digit;
        cin >> digit;
        a[i][j] = digit - '0';
      }
    }

    let total_count = 0;
    let layers = min(n, m) / 2;

    for (let k = 0; k < layers; k++)
    {
      vector<let> layer;

      for (let j = k; j < m - k; j++)
      {
        layer.pb(a[k][j]);
      }

      for (let i = k + 1; i < n - k - 1; i++)
      {
        layer.pb(a[i][m - k - 1]);
      }

      for (let j = m - k - 1; j >= k; j--)
      {
        layer.pb(a[n - k - 1][j]);
      }

      for (let i = n - k - 2; i > k; i--)
      {
        layer.pb(a[i][k]);
      }

      total_count += countPattern(layer);
    }

    cout << total_count << endl;
  }
  return 0;
}