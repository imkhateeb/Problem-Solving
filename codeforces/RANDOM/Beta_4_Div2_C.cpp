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
  map<string, int> m;
  while (T--)
  {
    string s;
    cin >> s;

    if (!m[s])
    {
      m[s] = 1;
      cout << "OK" << endl;
    }
    else
    {
      cout << s << m[s] << endl;
      m[s]++;
    }
  }

  return 0;
}