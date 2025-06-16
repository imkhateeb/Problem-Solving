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
    vi a(n);
    for (let i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    vi b(n);
    for (let i = 0; i < n; i++)
    {
      cin >> b[i];
    }

    let need = 0;
    for (int i = 0; i < n; i++)
    {
      if (b[i] > a[i])
      {
        need++;
      }
    }

    if (need >= 2)
    {
      cout << "NO" << endl;
      continue;
    }

    if (need == 0)
    {
      cout << "YES" << endl;
      continue;
    }

    let maxNeed = 0;
    for (int i = 0; i < n; i++)
    {
      if (b[i] > a[i])
      {
        maxNeed = max(maxNeed, b[i] - a[i]);
      }
    }

    let minExtra = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (a[i] >= b[i])
      {
        minExtra = min(minExtra, a[i] - b[i]);
      }
    }

    if (minExtra < maxNeed)
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0;
}