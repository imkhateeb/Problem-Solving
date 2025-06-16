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
    let n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int x = 0;
    int y = 0;

    bool isFound = false;
    bool isFlag = false;

    int p = 10000;

    while (p--)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == 'N')
        {
          y++;
        }
        else if (s[i] == 'S')
        {
          y--;
        }
        else if (s[i] == 'W')
        {
          x--;
        }
        else if (s[i] == 'E')
        {
          x++;
        }
        {
          if (x == a && y == b)
          {
            isFound = true;
            break;
          }
        }
      }

      if (isFound)
      {
        break;
      }
      if (x == 0 && y == 0)
      {
        break;
      }
    }

    if (isFound)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}
