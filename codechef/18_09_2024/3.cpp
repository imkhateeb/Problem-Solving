#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    vector<string> vs;

    for (int i = 0; i < m; i++)
    {
      string s;
      cin >> s;
      vs.pb(s);
    }

    vector<int> ones(n, 0);
    vector<int> zeros(n, 0);
    vector<int> ques(n, 0);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (vs[i][j] == '1')
        {
          ones[j]++;
        }
        else if (vs[i][j] == '0')
        {
          zeros[j]++;
        }
        else
        {
          ques[j]++;
        }
      }
    }

    long long ans = 0;
    long long ans2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (ques[i] == 0)
      {
        ans += ones[i] * 1LL * zeros[i];
        ans2 += ones[i] * 1LL * zeros[i];
      }
      else
      {
        int x = (m + 1) / 2;
        int y = m - x;

        int zReq = x - zeros[i];
        int oReq = y - ones[i];

        if (zReq >= 0 && oReq >= 0)
        {
          ans += x * 1LL * y;
        }
        else if (zReq >= 0)
        {
          ans += (ones[i] * 1LL * (ques[i] + zeros[i]));
        }
        else
        {
          ans += (zeros[i] * 1LL * (ques[i] + ones[i]));
        }

        zReq = y - zeros[i];
        oReq = x - ones[i];

        if (zReq >= 0 && oReq >= 0)
        {
          ans2 += x * 1LL * y;
        }
        else if (zReq >= 0)
        {
          ans2 += (ones[i] * 1LL * (ques[i] + zeros[i]));
        }
        else
        {
          ans2 += (zeros[i] * 1LL * (ques[i] + ones[i]));
        }
      }
    }

    cout << max(ans, ans2) << endl;
  }

  return 0;
}