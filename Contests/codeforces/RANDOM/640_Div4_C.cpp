#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{

  let t;
  cin >> t;
  while (t--)
  {
    let n, k;
    cin >> n >> k;
    let need = k / (n - 1);
    if (k % (n - 1) == 0)
      need--;

    cout << k + need << endl;
  }

  return 0;
}