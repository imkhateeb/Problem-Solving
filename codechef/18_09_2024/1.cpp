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
    int M, P;
    cin >> M >> P;

    int cnt = 0;
    while (M != 299 && ((P + (20 * (cnt + 1)) + M + 1) <= 1000))
    {
      cnt++;
      M++;
    }

    cout << cnt << endl;
  }

  return 0;
}