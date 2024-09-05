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
    /*------------------------ VARIABLES -----------------------*/
    let n;
    cin >> n;
    vpii points;

    for (int i = 0; i < n; i++)
    {
      let x, y;
      cin >> x >> y;
      points.pb({x, y});
    }

    let x, y, p, q;
    cin >> x >> y >> p >> q;

    /*--------------------- START --- CODE ---------------------*/

    let refDistance = ((x - p) * (x - p)) + ((y - q) * (y - q));
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
      let x1 = points[i].ff;
      let y1 = points[i].ss;

      let dist = ((x1 - p) * (x1 - p)) + ((y1 - q) * (y1 - q));

      if (refDistance < dist)
      {
        continue;
      }
      else
      {
        flag = false;
        break;
      }
    }

    if (flag)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}
