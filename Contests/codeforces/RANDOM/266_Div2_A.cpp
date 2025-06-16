#include <bits/stdc++.h>

using namespace std;

#define let long long

int main()
{

  let n, m, a, b;
  cin >> n >> m >> a >> b;

  double unit = (double)b / m;

  if (unit >= a)
  {
    cout << n * a << endl;
  }
  else
  {
    let ans = (n / m) * b + min((n % m) * a, b);
    cout << ans << endl;
  }

  return 0;
}