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

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;

    vector<let> a(n);

    for (let i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    if (n == 2)
    {
      if (a[0] == a[1])
      {
        cout << 1 << endl;
      }
      else if (a[0] > a[1])
      {
        if ((a[0] + a[1]) % 2 == 0)
        {
          cout << (1000000 - (((a[0] + a[1]) / 2) - 1)) << endl;
        }
        else
        {
          cout << (1000000 - ((a[0] + a[1]) / 2)) << endl;
        }
      }
      else
      {
        cout << ((a[0] + a[1]) / 2) << endl;
      }
    }
    else
    {

      bool flag = false;
      vector<int> temp;
      for (let i = 1; i < n; i++)
      {
        temp.pb(a[i]);
        if (a[0] == a[i])
        {
          cout << 1 << endl;
          flag = true;
          break;
        }
      }

      if (flag)
      {
        continue;
      }

      sort(all(temp));

      int left = 0;
      int right = n;

      for (let i = 0; i < n - 1; i++)
      {
        if (a[0] > temp[i] && a[0] < temp[i + 1])
        {
          left = i;
          right = i + 1;
          break;
        }
      }

      if ()

        let ans = 0;
      ans += (a[0] + a[right]) / 2;

      if ((a[0] + a[left]) % 2 == 0)
      {
      }
    }
  }

  return 0;
}
