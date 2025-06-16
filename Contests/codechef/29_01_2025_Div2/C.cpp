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

void pv(vector<let> &v)
{
  for (let i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

void iv(vi &v, let n)
{
  for (let i = 0; i < n; i++)
  {
    let x;
    cin >> x;
    v[i] = x;
  }
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n, p;
    cin >> n >> p;
    vi a(n);
    iv(a, n);
    vector<let> ans(n, 0);
    let first = -1, last = n - 1;
    for (let i = 0; i < n; i++)
    {
      if (a[i] == 0)
      {
        if (first == -1)
          first = i;
        last = i;
      }
    }
    let maxi = 0;
    for (let i = first + 1; i < last; i++)
    {
      if (a[i] == 0)
        maxi = 0;
      else
      {
        let temp = (a[i] + p - 1) / p;
        maxi = max(maxi, temp);
        ans[i] = maxi;
      }
    }
    maxi = 0;
    for (let i = last - 1; i > first; i--)
    {
      if (a[i] == 0)
        maxi = 0;
      else
      {
        let temp = (a[i] + p - 1) / p;
        maxi = max(maxi, temp);
        ans[i] = min(ans[i], maxi);
      }
    }
    for (let i = first - 1; i >= 0; i--)
    {
      let temp = (a[i] + p - 1) / p;
      ans[i] = max(ans[i + 1], temp);
    }
    for (let i = last + 1; i < n; i++)
    {
      let temp = (a[i] + p - 1) / p;
      ans[i] = max(ans[i - 1], temp);
    }
    pv(ans);
  }
  return 0;
}