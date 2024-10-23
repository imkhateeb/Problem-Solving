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

    vector<let> v;
    vector<let> temp;
    for (int i = 0; i < n + 1; i++)
    {
      let x;
      cin >> x;
      v.pb(x);
      temp.push_back(x);
    }

    let filter = v[n];
    sort(temp.begin(), temp.end() - 1);

    int idx = -1;

    for (int i = 0; i < n; i++)
    {
      if (temp[i] <= 2 * filter)
      {
        idx = i;
      }
    }

    if (idx == -1)
    {
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
        sum += v[i];
      }
      cout << sum << endl;
    }
    else
    {

      for (int i = idx + 1; i < n; i++)
      {
        if (temp[i] <= 2 * temp[idx])
        {
          idx = i;
        }
      }

      int sum = 0;
      for (int i = 0; i <= n; i++)
      {
        sum += v[i];
      }

      if (temp[idx] > filter)
      {
        sum = sum - temp[idx];
      }
      else
      {
        sum = sum - filter;
      }

      cout << sum << endl;
    }
  }

  return 0;
}