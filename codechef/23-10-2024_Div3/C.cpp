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

    string s;
    cin >> s;

    int ones = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '1')
      {
        ones++;
      }
    }

    if (ones == 0)
    {
      cout << s.size() << endl;
    }
    else
    {

      if (ones % 2 == 0)
      {
        cout << 0 << endl;
      }
      else
      {
        cout << 1 << endl;
      }
    }
  }

  return 0;
}