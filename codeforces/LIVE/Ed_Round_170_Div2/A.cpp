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

    string p, q;

    cin >> p >> q;

    int cnt1 = 0;

    for (int i = 0; i < min(p.size(), q.size()); i++)
    {
      if (p[i] == q[i])
      {
        cnt1++;
      }
      else
      {
        break;
      }
    }
    if (cnt1 == 0)
    {
      cout << p.size() + q.size() << endl;
      continue;
    }
    else
    {
      cout << cnt1 + 1 + (p.size() - cnt1 + (q.size() - cnt1)) << endl;
    }
  }

  return 0;
}