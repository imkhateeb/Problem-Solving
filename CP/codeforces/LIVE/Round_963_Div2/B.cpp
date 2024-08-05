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
    cin >> n;
    fillVec(v, n);

    /*--------------------- START --- CODE ---------------------*/

    let max_odd = INT_MIN;

    let operations = 0;

    for (int i = 0; i < n; i++)
    {
      if (v[i] % 2 == 1)
      {
        max_odd = max(max_odd, v[i]);
      }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
      if (v[i] % 2 == 0 && v[i] < max_odd)
      {
        operations++;
        v[i] = v[i] + max_odd;
        max_odd = v[i];
      }
    }

    bool isEvenRemaining = false;
    for (int i = 0; i < n; i++)
    {
      if (v[i] % 2 == 0)
      {
        isEvenRemaining = true;
        break;
      }
    }

    if (!isEvenRemaining)
    {
      cout << operations << endl;
    }
    else
    {

      int evens = 0;
      for (int i = 0; i < n; i++)
      {
        if (v[i] % 2 == 0)
        {
          evens++;
        }
      }

      if (evens == n)
      {
        cout << 0 << endl;
      }
      else
      {
        cout << operations + evens + 1 << endl;
      }
    }

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}