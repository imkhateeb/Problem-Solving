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
    vi a(n), b(n);

    for (let i = 0; i < n; i++)
      cin >> a[i];

    for (let i = 0; i < n; i++)
      cin >> b[i];

    let maxB = LLONG_MIN;
    int idx = 0;
    for (let i = 0; i < n; i++)
    {
      if (b[i] > a[i] && maxB < b[i])
      {
        maxB = b[i];
        idx = i;
      }
    }

    vector<let> temp;
    for (let i = 0; i < n; i++)
    {
      if (i == idx)
      {
        continue;
      }
      else if (b[i] > a[i])
      {
        temp.pb(b[i]);
      }
    }

    let need = maxDiff;
    sort(all(temp), greater<let>());

    for (let i = 0; i < temp.size(); i++)
    {
      need += (let)pow(2, (i + 1)) * temp[i];
    }

    let minSurplus = LLONG_MAX;
    for (let i = 0; i < n; i++)
    {
      if (b[i] > 0 && a[i] > b[i])
      {
        minSurplus = min(minSurplus, a[i] - b[i]);
      }
    }

    if (need <= minSurplus)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}
