#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{

  let t;
  cin >> t;

  while (t--)
  {

    let n, x, k;
    cin >> n >> x >> k;

    string s;
    cin >> s;

    let strLen = s.size();

    let inversions = 0;
    let ones = 0;

    for (int i = 0; i < strLen; i++)
    {
      if (s[i] == '1')
      {
        ones++;
      }
      else
      {
        inversions += ones;
      }
    }

    if ((inversions > x) || (inversions % k != 0))
    {
      cout << 2 << endl;
    }
    else
    {
      cout << 1 << endl;
    }
  }

  return 0;
}