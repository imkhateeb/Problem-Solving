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
    let n, k;
    cin >> n >> k;

    vi a(n);
    for (let i = 0; i < n; i++)
      cin >> a[i];

    let sum = 0;
    let extram = 0;
    let extrap = 0;

    for (let i = 0; i < n; i++)
    {
      let quotient = a[i] / k;
      let remainder = a[i] % k;

      sum += quotient;

      if (remainder != 0)
      {
        if (a[i] > 0)
          extrap++;
        else
          extram--;
      }
    }

    if (sum == 0 ||
        (sum > 0 && (sum + extram) <= 0) ||
        (sum < 0 && (sum + extrap) >= 0))
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