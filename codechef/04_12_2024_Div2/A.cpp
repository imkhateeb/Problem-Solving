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
    let N, X;
    cin >> N >> X;
    vi A(N), B(N);
    for (let i = 0; i < N; i++)
      cin >> A[i];
    for (let i = 0; i < N; i++)
      cin >> B[i];

    vector<let> cost;

    for (let i = 0; i < N; i++)
    {
      cost.push_back(A[i] * B[i]);
    }

    sort(cost.rbegin(), cost.rend());

    let i = 0;
    let cnt = 0;

    while (X > 0 && i < N)
    {
      X = X - cost[i];
      i++;
      cnt++;
      if (X < 0)
      {
        break;
      }
    }

    if (X > 0)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << cnt << endl;
    }
  }

  return 0;
}