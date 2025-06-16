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

// Optimize this code

int main()
{
  let T;
  cin >> T;
  while (T--)
  {

    let n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }

    let sum = 0;
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
      if (v[i - 1] == v[i])
      {
        cnt++;
      }
      else
      {
        sum = sum + ((cnt * 1LL * (cnt + 1)) / 2);
        cnt = 1;
      }
    }

    sum = sum + ((cnt * 1LL * (cnt + 1)) / 2);

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
      if (v[i] == 1)
      {
        a++;
      }
      if (v[i] == 2)
      {
        b++;
      }
      if (v[i] == 3)
      {
        c++;
      }

      int x = a;
      int y = b;
      int z = c;

      if (a > 0 && c > 0 && a == c && b > 0)
      {
        sum++;
      }
      int j = 0;
      while (x && y && z)
      {
        if (v[j] == 1)
        {
          x--;
        }
        if (v[j] == 2)
        {
          y--;
        }
        if (v[j] == 3)
        {
          z--;
        }

        if (x > 0 && z > 0 && x == z && y > 0)
        {
          sum++;
        }
        j++;
      }
    }

    cout << sum << endl;
  }

  return 0;
}