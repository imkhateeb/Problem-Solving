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
    v.push_back(x);
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
/*----------------------- MAIN --- CODE ------------------------*/

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    /*------------------------ VARIABLES -----------------------*/
    let n, flag = false, cnt = 0, temp, a, b, x, y, z, p, q, r;
    string str = "", tempStr = "", s;
    vi v;

    /*------------------------- INPUTS -------------------------*/
    cin >> s;

    /*--------------------- START --- CODE ---------------------*/
    if (s.size() == 1)
    {
      if (s[0] == 'a')
      {
        cout << "ab" << endl;
      }
      else if (s[0] == 'z')
      {
        cout << "za" << endl;
      }
      else
      {
        cout << s[0] << (char)(s[0] - 1) << endl;
      }
    }
    else
    {

      bool isDone = false;

      for (int i = 0; i < s.size() - 1; i++)
      {
        if (!isDone)
        {
          cout << s[i];
          if (s[i] == s[i + 1])
          {
            if (s[i] == 'a')
            {
              cout << "b";
            }
            else
            {
              cout << "a";
            }
            isDone = true;
          }
        }
        else
        {
          cout << s[i];
        }
      }
      cout << s[s.size() - 1];

      if (isDone)
      {
        cout << endl;
      }
      else
      {
        if (s[s.size() - 1] == 'a')
        {
          cout << "b" << endl;
        }
        else
        {
          cout << "a" << endl;
        }
      }
    }
  }
  /*---------------------- END --- CODE ----------------------*/
  return 0;
}
