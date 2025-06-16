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

  vi a(n);

  for (let i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  if (n == 1)
  {
    cout << "yes" << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  else if (n == 2)
  {
    cout << "yes" << endl;
    if (a[0] < a[1])
    {
      cout << 1 << " " << 1 << endl;
    }
    else
    {
      cout << 1 << " " << 2 << endl;
    }
  }

  vector<pair<let, let>> segements;

  bool isInc = v[0] < v[1];
  let start = 0;

  for (let i = 1; i < n; i++)
  {
    if (isInc && v[i] < v[i - 1])
    {
      segements.pb(mp(start, i));
      start = i;
      isInc = !isInc;
    }
    else if (!isInc && v[i] > v[i - 1])
    {
      segements.pb(mp(start, i));
      start = i;
      isInc = !isInc;
    }
  }

  if (segments.size() >= 3)
  {
    cout << "no" << endl;
  }
  else if (segments.size() == 0 && isInc)
  {
    cout << "yes" << endl;
    cout << 1 << " " << 1 << endl;
  }
  else if (segments.size() == 0 && !isInc)
  {
    cout << "yes" << endl;
    cout << 1 << " " << n << endl;
  } else {
    if (segments[0].first == 0 && segments[segments.size() - 1].second == n - 1)
    {
      cout << "yes" << endl;
      cout << segments[0].first + 1 << " " << segments[segments.size() - 1].second + 1 << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }

  return 0;
}