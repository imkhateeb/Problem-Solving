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

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }

    let sum = 0;
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
      if (v[i - 1] == v[i])
      {
        cnt++;
      }
      else
      {
        sum = sum + ((cnt * 1LL * (cnt + 1)) / 2);
        cnt = 1;
      }
    }

    sum = sum + ((cnt * 1LL * (cnt + 1)) / 2);

    cout << sum << endl;
  }

  return 0;
}