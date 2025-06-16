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

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    if (n == 2)
    {
      cout << a[1] - a[0] << endl;
    }
    else
    {
      let temp = a[n - 2];
      for (int i = 0; i < n - 2; i++)
      {
        temp = temp - a[i];
      }

      cout << a[n - 1] - temp << endl;
    }
  }

  return 0;
}