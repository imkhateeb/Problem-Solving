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
    let x;
    cin >> x;

    if (x == 1 || x == 2 || x == 3)
    {
      cout << "NO" << endl;
    }
    else
    {
      let sqt = sqrt(x);

      if (sqt * sqt == x)
      {
        bool flag = true;
        for (let i = 2; i * i <= sqt; i++)
        {
          if (x % i == 0)
          {
            cout << "NO" << endl;
            flag = false;
            break;
          }
        }
        if (flag)
          cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}