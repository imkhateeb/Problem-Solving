#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{
  let x;
  cin >> x;

  let ans = 0;
  let factor = 1;

  while (x > 0)
  {
    let dgt = x % 10;
    x = x / 10;

    if (((9 - dgt) > 0 && (9 - dgt) < dgt) || (((9 - dgt) == 0) && x > 0))
    {
      ans = ans + (9 - dgt) * factor;
    }
    else
    {
      ans = ans + dgt * factor;
    }
    factor = factor * 10;
  }

  cout << ans << endl;

  return 0;
}