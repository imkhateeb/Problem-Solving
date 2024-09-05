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
    string str = "", tempStr = "", s1, s2;
    vi v;

    /*------------------------- INPUTS -------------------------*/
    cin >> n;
    cin >> s1;
    cin >> s2;

    /*--------------------- START --- CODE ---------------------*/

    cnt = 1;
    let maxi = 0;

    str.pb(s1[0]);
    for (int i = 1; i < n; i++)
    {

      if (s1[i] == s2[i - 1])
      {
        str.pb(s1[i]);
        cnt++;
        if (i == n - 1)
        {
          str.pb(s2[i]);
          break;
        }
      }
      else // Corrected the syntax here
      {
        if (s1[i] == '0')
        {
          cnt = 1;
          if (i == n - 1)
          {
            str.pb(s1[i]);
            str.pb(s2[i]);
            break;
          }
          else
          {
            str.pb(s1[i]);
          }
          
        }
        else
        {
          i = i - 1;
          while (i < n)
          {
            str.pb(s2[i]);
            i++;
          }
        }
      }
    }
    cout << str << endl;
    cout << cnt << endl;
    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}