#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<let>
#define vvi vector<vector<let>>
#define vs vector<string>
#define vpii vector<pair<let, let>>
using namespace std;

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    let maxFibonacciness = 0;

    for (let a3 = -300; a3 <= 300; ++a3)
    {
      let count = 0;
      if (a4 == a2 + a3)
        count++;
      if (a5 == a3 + a4)
        count++;
      if (a3 == a1 + a2)
        count++;
      maxFibonacciness = max(maxFibonacciness, count);
    }

    cout << maxFibonacciness << endl;
  }

  return 0;
}
