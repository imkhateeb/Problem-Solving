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
    let N, K;
    cin >> N >> K;

    if (K == 1)
    {
      cout << -1 << endl;
      continue;
    }

    vi perm(N);
    for (let i = 0; i < N; i++)
      perm[i] = i + 1;

    bool found = false;
    do
    {
      bool isGood = true;
      for (let i = 0; i < N; i++)
      {
        if (perm[i] % K == (i + 1) % K)
        {
          isGood = false;
          break;
        }
      }
      if (isGood)
      {
        found = true;
        for (let x : perm)
          cout << x << " ";
        cout << endl;
        break;
      }
    } while (next_permutation(perm.begin(), perm.end()));

    if (!found)
      cout << "-1" << endl;
  }

  return 0;
}