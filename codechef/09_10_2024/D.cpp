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
    let n, m;
    cin >> n >> m;

    if (n > m)
    {
      for (let i = 1; i <= n; i++)
      {
        for (let j = 1; j <= m; j++)
        {
          if (i <= j)
          {
            if (i == j)
            {
              cout << "3 ";
            }
            else
            {
              cout << "2 ";
            }
          }
          else
          {
            if (j == m)
            {
              cout << "3 ";
            }
            else
            {
              cout << "2 ";
            }
          }
        }
        cout << endl;
      }
    }
    else if (m > n)
    {
      for (let i = 1; i <= n; i++)
      {
        for (let j = 1; j <= m; j++)
        {
          if (i == j || (j > i && i == n))
          {
            cout << "3 ";
          }
          else
          {
            cout << "2 ";
          }
        }
        cout << endl;
      }
    }
    else
    {
      for (let i = 1; i <= n; i++)
      {
        for (let j = 1; j <= m; j++)
        {
          if (i == j)
          {
            cout << "3 ";
          }
          else
          {
            cout << "2 ";
          }
        }
        cout << endl;
      }
    }
  }

  return 0;
}