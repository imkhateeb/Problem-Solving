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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    if (n <= 3)
    {
      cout << 0 << endl;
      continue;
    }

    int diff1, diff2, diff3;

    sort(a.begin(), a.end());

    diff1 = a[n - 1] - a[2];

    diff2 = a[n - 2] - a[1];

    diff3 = a[n - 3] - a[0];

    cout << min(diff1, min(diff2, diff3)) << endl;
  }

  return 0;
}
