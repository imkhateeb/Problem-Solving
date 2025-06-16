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
    let n, b, c;
    cin >> n >> b >> c;

    if (b == 0)
    {
      if (n - c <= 2)
      {
        if (c < n)
        {
          cout << n - 1 << endl;
        }
        else
        {
          cout << n << endl;
        }
      }
      else
      {
        cout << -1 << endl;
      }
    } else if ( c >= n ) {
      cout << n << endl;
    }
    else
    {
      let result;
      if ((n - c) % b == 0 && (n - c) >= 0)
      {
        result = n - ((n - c) / b + 1) + 1;
      }
      else
      {
        result = n - ((n - c) / b + 1);
      }
      cout << result << endl;
    }
  }

  return 0;
}