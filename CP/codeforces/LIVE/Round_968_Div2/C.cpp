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

    vector<pair<int, char>> v(26, {0, 0});

    for (int i = 0; i < n; i++)
    {
      v[s[i] - 'a'].first++;
      v[s[i] - 'a'].second = s[i];
    }

    sort(v.rbegin(), v.rend());

    vector<char> temp(n);

    int i = 0;
    for (int j = 0; j < 26; j++)
    {
      while (v[j].first--)
      {
        temp[i] = v[j].second;
        i += 2;
        if (i >= n)
        {
          i = 1;
        }
      }
    }

    string str = "";
    for (int i = 0; i < n; i++)
    {
      str.push_back(temp[i]);
    }

    cout << str << endl;
  }

  return 0;
}
