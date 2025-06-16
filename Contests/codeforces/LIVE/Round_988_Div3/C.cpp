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
using namespace std;

bool isComposite(let x)
{
  if (x <= 3)
    return false;
  for (let i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
      return true;
  }
  return false;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;

    vector<int> a;

    if (n == 2 || n == 3 || n == 4)
    {
      cout << -1 << endl;
      continue;
    }

    for (int i = 1; i <= n; i += 2)
    {
      if (i == 5)
      {
        continue;
      }
      a.pb(i);
    }

    a.pb(5);
    a.pb(4);

    for (int i = 2; i <= n; i += 2)
    {
      if (i == 4)
      {
        continue;
      }
      a.pb(i);
    }

    for (let i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
