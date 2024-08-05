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
    let n, flag = false, cnt = 0;
    string str = "", tempStr = "", s;
    vi v;

    /*------------------------- INPUTS -------------------------*/
    cin >> n;
    cin >> s;

    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    /*--------------------- START --- CODE ---------------------*/

    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == 'A')
      {
        a++;
      }
      else if (s[i] == 'B')
      {
        b++;
      }
      else if (s[i] == 'C')
      {
        c++;
      }
      else if (s[i] == 'D')
      {
        d++;
      }
    }

    let sum = 0;

    if (a >= n)
    {
      sum += n;
    }
    else
    {
      sum += a;
    }

    if (b >= n)
    {
      sum += n;
    }
    else
    {
      sum += b;
    }

    if (c >= n)
    {
      sum += n;
    }
    else
    {
      sum += c;
    }

    if (d >= n)
    {
      sum += n;
    }
    else
    {
      sum += d;
    }

    cout << sum << endl;
    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}