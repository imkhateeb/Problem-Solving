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

let calculateInversions(const string &s)
{
  let ones = 0, inversions = 0;
  for (char c : s)
  {
    if (c == '1')
    {
      ones++;
    }
    else
    {
      inversions += ones;
    }
  }
  return inversions;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let N, X, K;
    cin >> N >> X >> K;
    string S;
    cin >> S;

    let totalInversions = calculateInversions(S);

    if (totalInversions == 0)
    {
      cout << 1 << endl;
      continue;
    }

    let ans = 0;
    if (K == 1)
    {
      cout << ((totalInversions / X) + (totalInversions % X)) << endl;
    }
    else
    {
      let factor = ((X / K) * K);
      let ans = 0;
      if (totalInversions % K)
      {
        ans++;
      }
      while (totalInversions > 0)
      {
        ans++;
        totalInversions = totalInversions - factor;
      }

      cout << ans << endl;
    }
  }

  return 0;
}
