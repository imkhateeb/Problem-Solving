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

    /*--------------------- START --- CODE ---------------------*/

    let max_xor = 0, max_i = -1, max_j = -1;

    for (let k = 0; k < 3 * n; k++)
    {
      let a = rand() % n;
      let b = rand() % n;
      let c = rand() % n;
      let d = rand() % n;

      cout << "? " << a << " " << b << " " << c << " " << d << endl;
      fflush(stdout);

      char response;
      cin >> response;

      if (response == '>')
      {
        if (max_xor < (v[a] ^ v[b]))
        {
          max_xor = v[a] ^ v[b];
          max_i = a;
          max_j = b;
        }
      }
    }

    cout << "! " << max_i << " " << max_j << endl;
    fflush(stdout);

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}
