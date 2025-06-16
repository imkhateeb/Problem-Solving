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
  let T;
  string str = "", tempStr = "", s;

  cin >> T;
  while (T--)
  {
    let n, flag = false, cnt = 0, temp, a, b, x, y, z, p, q, r;
    cin >> n >> q;
    vi v;
    fillVec(v, n);
    /*---------- START --- CODE ----------*/

    map<let, bool> m1;
    map<let, pair<int, int>> m2;

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        cnt = 0;
        for (int k = 0; k < n; k++)
        {

          if (k == i || k == j)
          {
            cnt += v[k];
          }
          else
          {
            cnt += (2 * v[k]);
          }
        }

        m1[cnt] = true;
        m2[cnt] = {i, j};
      }
    }

    while (q--)
    {
      cin >> x;

      if (m1[x])
      {
        int i = m2[x].first;
        int j = m2[x].second;

        cout << v[i] << " ";
        for (int k = 0; k < n; k++)
        {
          if (k != i && k != j)
          {
            cout << v[k] << " ";
          }
        }
        cout << v[j] << endl;
      }
      else
      {
        cout << -1 << endl;
      }
    }

    /*---------- END --- CODE ----------*/
    // printVec(v);
  }

  return 0;
}