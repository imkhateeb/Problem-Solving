#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{
  let n, l;
  cin >> n >> l;

  vector<let> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  double max_gap = 0;
  for (int i = 0; i < n - 1; i++)
  {
    max_gap = max(max_gap, (v[i + 1] - v[i]) / 2.0);
  }

  double boundary_gap = max(v[0], l - v[n - 1]);

  double ans = max(max_gap, boundary_gap);

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
