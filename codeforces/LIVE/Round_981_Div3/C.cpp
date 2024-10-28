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
    vi v(n);
    for (int i = 0; i < n; i++)
    {
      let x;
      cin >> x;
      v[i] = x;
    }

    int i = 0;
    int j = 0;

    if (n % 2 == 0)
    {
      i = (n / 2) - 1;
      j = n / 2;
    }
    else
    {
      i = n / 2 - 1;
      j = n / 2 + 1;
    }

    while (i >= 0)
    {
      if (v[i] != v[j])
      {
        if (i == 0 && v[i] == v[i + 1])
        {
          swap(v[i], v[j]);
        }
        else if (i == 0 && v[j] == v[j - 1])
        {
          swap(v[j], v[i]);
        }
        else if (i != 0)
        {
          if (v[i] == v[i + 1] && v[i] == v[i - 1])
          {
            swap(v[i], v[j]);
          }
          else if (v[i] == v[1 - 1] || v[i] == v[i + 1])
          {
            if (v[i] != v[j - 1] && v[i] != v[j + 1])
            {
              swap(v[i], v[j]);
            }
          }
          else
          {
            if (v[j] == v[j + 1] && v[j] == v[j - 1])
            {
              swap(v[i], v[j]);
            }
            else if (v[j] == v[j - 1] || v[j] == v[j + 1])
            {
              if (v[j] != v[i - 1] && v[j] != v[i + 1])
              {
                swap(v[i], v[j]);
              }
            }
          }
        }
      }
      i--;
      j++;
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
      if (v[i] == v[i + 1])
      {
        ans++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}