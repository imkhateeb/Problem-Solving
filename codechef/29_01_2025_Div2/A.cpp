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

/**Reusable functions */
void pv(vi &v)
{
  for (let i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

void iv(vi &v, let n)
{
  for (let i = 0; i < n; i++)
  {
    let x;
    cin >> x;
    v.pb(x);
  }
}

/**Main function */
int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let m, k;
    cin >> m >> k;
    string s;
    cin >> s;

    let cnt = 0;
    for (let i = 0; i < m; i++)
    {
      if (s[i] == 'S')
      {
        cnt++;
      }
    }

    if (cnt >= k)
    {
      cout << m << endl;
    }
    else
    {
      cout << m + (k - cnt - 1) << endl;
    }
  }

  return 0;
}
