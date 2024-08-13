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
    let n;
    cin >> n;
    vi a, b;

    /*------------------------- INPUTS -------------------------*/
    fillVec(a, n);
    fillVec(b, n);

    /*--------------------- START --- CODE ---------------------*/
    bool flag = true;

    int i = 0;
    int j = n - 1;
    int p = 0;
    int q = n - 1;

    while (i <= j)
    {
      if (a[i] == b[p] && a[j] == b[q])
      {
        i++;
        p++;
      }
      else if (a[i] == b[q] && a[j] == b[p])
      {
        i++;
        q--;
      }
      else
      {
        flag = false;
        break;
      }
    }

    if (flag)
    {
      cout << "Bob" << endl;
    }
    else
    {
      cout << "Alice" << endl;
    }
    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}
