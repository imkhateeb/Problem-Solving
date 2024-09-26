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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  let T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++)
    {
      cin >> p[i];
    }

    let i;
    for (i = n - 1; i >= 0; i--)
    {
      if (p[i] != i + 1)
      {
        break;
      }
    }

    if (i == -1)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << i + 2 << endl;
    }
  }

  return 0;
}