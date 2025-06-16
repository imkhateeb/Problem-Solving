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
    let n, x;
    cin >> n >> x;

    let odds = 0;
    for (let i = 0; i < n; i++)
    {
      let a;
      cin >> a;
      if (a % 2 == 1)
      {
        odds++;
      }
    }

    let evens = n - odds;

    if (odds % 2 == 0 && odds > 0)
    {
      odds--;
    }
    let temp = evens;
    if (temp % 2 == 0 && temp > 0)
      temp--;

    if (x % 2 == 0 && (temp <= 0 || odds + temp < x))
    {
      cout << "No" << endl;
    }
    else
    {
      if (odds >= x)
      {
        cout << "Yes" << endl;
      }
      else if (evens >= x - odds && odds > 0)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}