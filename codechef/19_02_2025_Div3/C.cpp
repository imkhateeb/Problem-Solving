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

    unordered_map<let, let> mp;
    for (let i = 0; i < n; i++)
    {
      mp[a[i]]++;
    }

    let totalZero = count(all(a), 0);
    let elementToRemove = 0;

    for (auto i : mp)
    {
      if (i.first != 0 && i.second > 1)
      {
        elementToRemove += (i.second / 2) * 2;
      }
    }

    if (elementToRemove > 0)
    {
      cout << (n - elementToRemove - totalZero) + 1 << endl;
    }
    else
    {
      if (totalZero > 0)
      {
        cout << n - totalZero + 1 << endl;
      }
      else
      {
        cout << n << endl;
      }
    }
  }

  return 0;
}
