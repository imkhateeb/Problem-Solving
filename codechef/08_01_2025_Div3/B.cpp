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
    string a;
    string b;
    cin >> a;
    cin >> b;

    let cnt = 0;
    let opts = 0;

    for (int i = 0; i < n; i++)
    {
      if (a[i] == '1' && b[i] == '1')
      {
        cnt++;
      }
      else if (a[i] == '1' && b[i] == '0')
      {
        opts++;
      }
      else if (a[i] == '0' && b[i] == '1')
      {
        opts++;
      }
    }

    if (cnt % 2 == 0 && opts == 0)
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0;
}