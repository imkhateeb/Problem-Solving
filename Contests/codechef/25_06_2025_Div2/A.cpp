#include <bits/stdc++.h>
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
#define let int

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let N;
    cin >> N;
    vi A(N);
    for (let i = 0; i < N; i++)
    {
      cin >> A[i];
    }
    A[0] = A[0]-1;

    let ans = INT_MAX;
    for (let i = 0; i < N; i++)
    {
      let time = max(i, A[i]+1);
      ans = min(ans, time);
    }

    cout << ans << endl;
  }

  return 0;
}
