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

int firstGreater(vector<let> &arr, let target)
{
  int l = 0, r = arr.size() - 1;
  while (l < r)
  {
    int m = l + (r - l) / 2;
    if (arr[m] <= target)
    {
      l = m + 1;
    }
    else
    {
      r = m;
    }
  }
  return l;
}

int lastSmaller(vector<let> &arr, let target)
{
  int l = 0, r = arr.size() - 1;
  while (l < r)
  {
    int m = l + (r - l + 1) / 2;
    if (arr[m] >= target)
    {
      r = m - 1;
    }
    else
    {
      l = m;
    }
  }
  return l;
}

int main()
{
  let T;
  cin >> T;
  let total = 1000000;
  while (T--)
  {
    let n;
    cin >> n;

    let a1;
    cin >> a1;

    vector<let> a(n - 1);
    for (let i = 0; i < n - 1; i++)
    {
      cin >> a[i];
    }

    sort(all(a));

    if (a1 <= a[0] && a1 >= a[n - 2])
    {
      cout << total << endl;
    }
    else if (a1 <= a[0])
    {
      let y = firstGreater(a, a1);
      let ans = (a[y] + a1) / 2;
      cout << ans << endl;
    }
    else if (a1 >= a[n - 2])
    {
      let x = lastSmaller(a, a1);
      let ans = total - ((a1 + a[x] + 1) / 2) + 1;
      cout << ans << endl;
    }
    else
    {
      let x, y;

      for (int i = 0; i < n - 1; i++)
      {
        if (a[i] >= a1)
        {
          x = a[i - 1];
          break;
        }
      }

      for (let i = 0; i < n - 1; i++)
      {
        if (a[i] > a1)
        {
          y = a[i];
          break;
        }
      }
      int temp = 1;

      temp += (((y + a1) / 2) - ((x + a1 + 1) / 2));

      cout << temp << endl;
    }
  }
  return 0;
}