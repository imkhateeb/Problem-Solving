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
    string s;
    cin >> s;

    let n = s.size();

    let minSize = n;

    let st = 0;
    let en = 0;

    let a = 0;
    let b = 0;
    let c = 0;

    for (let i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        a++;
      }
      else if (s[i] == '2')
      {
        b++;
      }
      else
      {
        c++;
      }
    }

    if (a == 0 || b == 0 || c == 0)
    {
      cout << 0 << endl;
      continue;
    }
    a = 0;
    b = 0;
    c = 0;

    while (en < n)
    {
      if (s[en] == '1')
      {
        a++;
      }
      else if (s[en] == '2')
      {
        b++;
      }
      else
      {
        c++;
      }

      while (a > 0 && b > 0 && c > 0)
      {
        minSize = min(minSize, en - st + 1);

        if (s[st] == '1')
        {
          a--;
        }
        else if (s[st] == '2')
        {
          b--;
        }
        else
        {
          c--;
        }

        st++;
      }
      en++;
    }

    cout << minSize << endl;
  }

  return 0;
}