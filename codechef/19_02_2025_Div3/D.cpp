#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define vs vector<string>
#define vpii vector<pair<long long, long long>>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long T;
  cin >> T;
  while (T--)
  {
    long long n;
    cin >> n;
    vi a(n);
    for (long long i = 0; i < n; i++)
      cin >> a[i];

    int ans = 0;
    for (int idx = 0; idx < n; idx++)
    {
      int maxElem = a[idx], temp = maxElem;
      int left = idx, right = (n - idx) - 1;

      if (left == 1 && right == 1)
      {
        int x = abs(maxElem - a[idx - 1]);
        int p = abs(x - a[idx + 1]);
        int y = abs(maxElem - a[idx + 1]);
        int q = abs(y - a[idx - 1]);
        temp = max(p, q);
      }
      else if (left == 1)
      {
        temp = abs(maxElem - a[idx - 1]);
      }
      else if (right == 1)
      {
        temp = abs(maxElem - a[idx + 1]);
      }

      ans = max(ans, temp);
    }

    cout << ans << endl;
  }

  return 0;
}