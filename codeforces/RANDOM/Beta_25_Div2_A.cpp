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
  let n;
  cin >> n;

  let odds = 0;
  let evens = 0;

  let firstEven = -1;
  let firstOdd = -1;

  for (let i = 1; i <= n; i++)
  {
    let x;
    cin >> x;

    if (x % 2 == 0)
    {
      evens++;
      if (firstEven == -1)
      {
        firstEven = i;
      }
    }
    else
    {
      odds++;
      if (firstOdd == -1)
      {
        firstOdd = i;
      }
    }
  }

  if (evens == 1)
  {
    cout << firstEven << endl;
  }
  else
  {
    cout << firstOdd << endl;
  }

  return 0;
}