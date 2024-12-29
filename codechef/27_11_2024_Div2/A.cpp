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

    vector<let> a(n);

    for (let i = 1; i < n; i++)
    {
      let x;
      cin >> x;
      a[i] = x;
    }

    a[0] = 1;

    sort(all(a));
    for (let i = 1; i < n; i++)
    {
      a[i] = a[i] - a[i - 1];
    }

    for (let i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
  }

  return 0;
}