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

void fillVec(vector<let> &v, let n)
{
  for (let i = 0; i < n; i++)
  {
    let x;
    cin >> x;
    v.pb(x);
  }
}

void printVec(vector<let> &v)
{
  let n = v.size();
  for (let i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

let power(let x, let y)
{
  let res = 1;
  for (let i = 0; i < y; i++)
  {
    res = res * x;
  }
  return res;
}

let powerWithMod(let x, let y, let p)
{
  let res = 1;
  x = x % p;
  if (x == 0)
    return 0;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    string s;
    cin >> n;
    cin >> s;

    int index = 0;

    int st = 0;
    int en = s.size() - 1;

    bool left = true;
    bool mid = false;

    while (en >= st)
    {
      if (s[en] != s[st])
      {
        if (s[en] < s[st])
        {
          left = false;
          break;
        }
        else
        {
          index = st;
          break;
        }
      }
      else if (st == en)
      {
        mid = true;
        break;
      }
      st++;
      en--;
    }

    int sz = s.size();
    if (!left && !mid)
    {
      for (int i = s.size() - 1; i >= 0; i--)
      {
        cout << s[i];
      }
      for (int i = 0; i < s.size(); i++)
      {
        cout << s[i];
      }
      cout << endl;
    }
    else
    {
      for (int i = 0; i < s.size(); i++)
      {
        cout << s[i];
      }
      cout << endl;
    }
  }

  return 0;
}
