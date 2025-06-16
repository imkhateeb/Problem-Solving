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

    if (k > n)
    {
      cout << "NO" << endl;
      continue;
    }

    if (n % 2 == 1)
    {
      if (k % 2 == 0)
      {
        cout << "NO" << endl;
      }
      else
      {
        cout << "YES" << endl;
        for (let i = 0; i < k - 1; i++)
        {
          cout << 1 << " ";
        }
        cout << n - k + 1 << endl;
      }
    }
    else
    {
      if (k % 2 == 0)
      {
        cout << "YES" << endl;
        for (let i = 0; i < k - 1; i++)
        {
          cout << 1 << " ";
        }
        cout << n - k + 1 << endl;
      }
      else
      {
        if (k * 2 > n)
        {
          cout << "NO" << endl;
        }
        else
        {
          cout << "YES" << endl;
          for (let i = 0; i < k - 1; i++)
          {
            cout << 2 << " ";
          }
          cout << n - 2 * k + 2 << endl;
        }
      }
    }
  }

  return 0;
}