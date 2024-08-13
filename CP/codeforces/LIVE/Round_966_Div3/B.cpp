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

/*----------------------- MAIN --- CODE ------------------------*/

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    /*------------------------ VARIABLES -----------------------*/
    let n;
    /*------------------------- INPUTS -------------------------*/
    cin >> n;
    vi v;
    fillVec(v, n);

    /*--------------------- START --- CODE ---------------------*/

    unordered_map<let, bool> m;
    bool flag = true;
    m[v[0]] = 1;

    for (let i = 1; i < n; i++)
    {
      if (!m[v[i] - 1] && !m[v[i] + 1])
      {
        flag = false;
        break;
      }
      else
      {
        m[v[i]] = true;
      }
    }

    if (flag)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}
