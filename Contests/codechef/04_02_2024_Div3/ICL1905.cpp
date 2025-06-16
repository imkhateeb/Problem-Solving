#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, a;
    cin >> n >> a;
    vector<int> c(n);
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
      cin >> c[i] >> d[i];
    }

    int cost_prefix[n];
    cost_prefix[0] = c[0];

    for (int i = 1; i < n; i++)
    {
      cost_prefix[i] = cost_prefix[i - 1] + c[i];
    }

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int maxi = d[i];
      int mini = d[i];
      for (int j = i; j < n; j++)
      {
        maxi = max(maxi, d[j]);
        mini = min(mini, d[j]);

        int cost = ((j - i + 1) * a) - ((cost_prefix[j] - (i > 0 ? cost_prefix[i - 1] : 0)) + ((maxi - mini) * (maxi - mini)));

        if (ans < cost)
        {
          ans = cost;
        }
      }
    }

    if ( ans < 0 ){
      cout << 0 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
