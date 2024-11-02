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

    vector<int> temp;
    let cnt = 1;
    for (let i = 0; i < n - 1; i++)
    {
      if (s[i] == s[i + 1])
      {
        cnt++;
      }
      else
      {
        temp.push_back(cnt);
        cnt = 1;
      }
    }
    temp.push_back(cnt);

    if (temp.size() == 1)
    {
      cout << temp[0] << endl;
    }
    else if (temp.size() == 2)
    {
      cout << max(temp[0], temp[1]) << endl;
    }
    else
    {
      let sum = 0;
      for (let i = 0; i < temp.size(); i++)
      {
        sum += temp[i];
      }

      if (temp.size() % 2)
      {
        cout << sum << endl;
      }
      else
      {
        if (temp[0] > temp[temp.size() - 1])
        {
          cout << sum - temp[temp.size() - 1] << endl;
        }
        else
        {
          cout << sum - temp[0] << endl;
        }
      }
    }
  }

  return 0;
}