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
/*-------------------------- MAIN --- CODE ---------------------------*/

int main()
{
  let T, n, flag = false, cnt = 0, temp, a, b, x, y, z, p, q, r;
  string str = "", tempStr = "", s;

  cin >> T;
  while (T--)
  {
    cin >> n;
    vi v;
    fillVec(v, n);
    /*---------- START --- CODE ----------*/
    cnt = 0;
    int a = 0;
    int maxi = INT_MAX;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      if (v[i] < mini)
      {
        mini = v[i];
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (v[i] == mini)
      {
        a++;
      }
    }

    if (a == 1)
    {

      for (int i = 0; i < n; i++)
      {

        if (v[i] < maxi && v[i] != mini)
        {
          maxi = v[i];
        }
      }
    }
    else
    {
      maxi = mini;
    }

    int mC = 0;
    int nC = 0;

    for (int i = 0; i < n; i++)
    {

      if (v[i] == maxi && mC == 0)
      {
        mC++;
        cnt += v[i];
      }
      else if (v[i] == mini && nC == 0)
      {
        nC++;
        cnt += v[i];
      }
      else
      {
        cnt += (v[i] * 2);
      }
    }

    cout << cnt << endl;

    /*---------- END --- CODE ----------*/
    // printVec(v);
  }

  return 0;
}