#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;

    vector<int> d(n, 0);
    while (q--)
    {
      int a, b, c;
      cin >> a >> b >> c;
      d[a] += c;
      d[b + 1] -= c;
    }

    long long prefix_sum[n];
    prefix_sum[0] = d[0];
    for (int i = 1; i < n; i++)
    {
      prefix_sum[i] = prefix_sum[i - 1] + d[i];
    }

    long long maxi = *max_element(prefix_sum, prefix_sum + n);
    cout << maxi << endl;
  }
  return 0;
}