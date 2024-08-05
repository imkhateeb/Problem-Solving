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
int findSmallestMissing(vector<let> &nums)
{
  int n = nums.size();

  for (int i = 0; i < n; ++i)
  {
    while (nums[i] >= 0 && nums[i] < n && nums[nums[i]] != nums[i])
    {
      swap(nums[i], nums[nums[i]]);
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (nums[i] != i)
    {
      return i;
    }
  }

  return n;
}

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

    let maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      if (maxi < v[i])
      {
        maxi = v[i];
      }
    }

    int missing = findSmallestMissing(v);
    bool first = false;
    bool second = false;

    if (missing == 0 && n > 1)
    {
      cout << 2 << endl;
      cout << 1 << " " << 1 << endl;
      cout << 2 << " " << n << endl;
    }
    else
    {
      let a1, a2, b1, b2;
      let flag = false;
      let target = ((missing * (missing - 1)) / 2);

      let sum = -1;
      map<let, bool> m;
      for (int i = 0; i < n; i++)
      {
        if (v[i] < missing)
        {
          if (!m[v[i]])
          {
            m[v[i]] = true;
            if (v[i] == 0)
            {
              sum++;
            }
            else
            {
              sum = sum + v[i];
            }
          }

          if (sum == target)
          {
            first = true;
            a1 = 1;
            a2 = i + 1;
            break;
          }
        }
      }
      if (first)
      {
        map<let, bool> m1;

        sum = -1;

        for (int i = a2; i < n; i++)
        {
          if (v[i] < missing)
          {
            if (!m1[v[i]])
            {
              m1[v[i]] = true;
              if (v[i] == 0)
              {
                sum++;
              }
              else
              {
                sum = sum + v[i];
              }
            }

            if (sum == target)
            {
              second = true;
              b1 = a1 + 1;
              b2 = n;
              break;
            }
          }
        }
      }

      if (first && second)
      {
        cout << 2 << endl;
        cout << a1 << " " << a2 << endl;
        cout << b1 << " " << b2 << endl;
      }
      else
      {
        cout << -1 << endl;
      }
    }

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}