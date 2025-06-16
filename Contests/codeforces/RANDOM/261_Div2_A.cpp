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
  let x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;

  let x_diff = x1 - x2;
  let y_diff = y1 - y2;

  if (x_diff != 0 && y_diff != 0 && abs(x_diff) != abs(y_diff))
  {
    cout << -1 << endl;
  }
  else
  {
    let a1, b1, a2, b2;
    if (x_diff == 0)
    {

      a1 = x1 + y_diff;
      b1 = y1;
      a2 = x2 + y_diff;
      b2 = y2;
    }
    else if (y_diff == 0)
    {

      a1 = x1;
      b1 = y1 + x_diff;
      a2 = x2;
      b2 = y2 + x_diff;
    }
    else
    {

      a1 = x1;
      b1 = y2;
      a2 = x2;
      b2 = y1;
    }

    cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
  }

  return 0;
}