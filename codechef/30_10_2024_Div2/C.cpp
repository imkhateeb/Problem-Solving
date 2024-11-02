#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

    vector<let> a(n);
    vector<let> b(n);

    for (let i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    for (let i = 0; i < n; i++)
    {
      cin >> b[i];
    }

    let tempSum = 0;
    vector<let> tempa;
    vector<let> tempb;

    let cnt = 0;
    let x = 0;

    for (let i = 0; i < n; i++)
    {
      if (a[i] >= b[i])
      {
        tempSum += b[i];
      }
      else
      {
        tempa.pb(a[i]);
        tempb.pb(b[i]);
        cnt++;
      }

      if (a[i] == b[i])
      {
        x++;
      }
    }

    if (cnt % 2 && x == 0)
    {
      let minIndex = 0;
      for (let i = 1; i < tempb.size(); i++)
      {
        if (tempb[i] < tempb[minIndex])
        {
          minIndex = i;
        }
      }

      let sum = 0;
      for (let i = 0; i < tempa.size(); i++)
      {
        if (i != minIndex)
        {
          sum += tempa[i];
        }
      }
      cout << sum + tempSum + tempb[minIndex] << endl;
    }
    else
    {
      let sum = 0;
      for (let i = 0; i < tempa.size(); i++)
      {
        sum += tempa[i];
      }
      cout << sum + tempSum << endl;
    }
  }

  return 0;
}
