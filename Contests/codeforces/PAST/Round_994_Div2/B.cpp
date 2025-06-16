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
    string s;
    cin >> s;

    bool pp = false;
    bool ss = false;

    bool df = false;
    bool ds = false;
    bool dotp = false;
    bool dots = false;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'p')
      {
        pp = true;
        if (df)
        {
          dotp = true;
        }
      }
      else if (s[i] == 's')
      {
        if (pp)
        {
          ss = true;
        }
        if (df)
        {
          dots = true;
        }
      }
      else
      {
        df = true;
        if (dotp && dots)
        {
          ds = true;
        }
      }
    }

    if (ss || ds)
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0;
}
