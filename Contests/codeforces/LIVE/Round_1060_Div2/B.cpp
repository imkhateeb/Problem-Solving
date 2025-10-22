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
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    int maxi = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (i % 2 == 0)
      {
        if (i == 0 && n > 1 && v[i] >= v[i + 1])
        {
          ans += 1;
        }
        else if (i > 0 && v[i] >= v[i - 1])
        {
          ans += (v[i] - v[i - 1] + 1);
        }
      }
      maxi = max(maxi, v[i]);
      if (i % 2 == 1) v[i] = maxi;
    }
    cout << ans << endl;
  }
  return 0;
}
