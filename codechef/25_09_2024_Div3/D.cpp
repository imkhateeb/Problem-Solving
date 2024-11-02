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

    unordered_map<let, let> m;

    int temp = (n - 1);
    while (temp)
    {
      let x, y;
      cin >> x >> y;

      if (m[x])
      {
        m[x]++;
      }
      else
      {
        m[x] = 1;
      }

      if (m[y])
      {
        m[y]++;
      }
      else
      {
        m[y] = 1;
      }

      temp--;
    }

    let ans = 0;

    for (int i = 1; i <= n; i++)
    {
      if (m[i] == 1)
      {
        ans = ans + 3;
      }
      else
      {
        ans = ans + 2;
      }
    }

    cout << ans << endl;
  }

  return 0;
}