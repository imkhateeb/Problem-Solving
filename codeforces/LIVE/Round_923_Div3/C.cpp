#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void fillVector(vector<int> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

int main()
{

  int T;
  cin >> T;
  while (T--)
  {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> fa(k + 1, 0);
    vector<int> fb(k + 1, 0);

    vector<int> a;
    vector<int> b;

    fillVector(a, n);
    fillVector(b, m);

    int acount = 0;
    int bcount = 0;

    vector<int> final;

    int maxi = max(n, m);
    for (int i = 0; i < maxi; i++)
    {
      if (i < n)
      {
        if ((a[i] <= k) && (a[i] >= 1))
        {
          if (fa[a[i]] == 0)
          {
            acount++;
            final.push_back(a[i]);
          }
          fa[a[i]]++;
        }
      }
      if (i < m)
      {
        if ((b[i] <= k) && (b[i] >= 1))
        {
          if (fb[b[i]] == 0)
          {
            bcount++;
            final.push_back(b[i]);
          }
          fb[b[i]]++;
        }
      }
    }

    if ((acount < k / 2) || (bcount < k / 2))
    {
      cout << "NO" << endl;
    }
    else
    {

      int x = final.size();
      int check[k + 1] = {0};
      for (int i = 0; i < x; i++)
      {
        check[final[i]]++;
      }

      int flag = 1;
      for (int i = 1; i <= k; i++)
      {
        if (check[i] < 1)
        {
          flag = 0;
          break;
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
    }
  }

  return 0;
}
