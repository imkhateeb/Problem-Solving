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
    string s;
    cin >> s;

    /*--------------------- START --- CODE ---------------------*/
    vector<pair<int, int>> vp;

    vector<let> prefix_sum(n, 0);
    prefix_sum[0] = v[0];
    for (let i = 1; i < n; i++)
    {
      prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    let ans = 0;

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
      while (i < j)
      {
        if (s[i] == 'L')
        {
          break;
        }
        i++;
      }

      while (i < j)
      {
        if (s[j] == 'R')
        {
          break;
        }
        j--;
      }

      if (i >= j)
      {
        break;
      }
      else
      {
        vp.push_back({i, j});
        i++;
        j--;
      }
    }

    for (int i = vp.size() - 1; i >= 0; i--)
    {
      int l = vp[i].first;
      int r = vp[i].second;
      if (l == 0)
      {
        ans += prefix_sum[r];
      }
      else
      {
        ans += prefix_sum[r] - prefix_sum[l - 1];
      }
    }

    cout << ans << endl;

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}
