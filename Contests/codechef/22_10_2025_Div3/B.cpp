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
    let N;
    cin >> N;
    vector<pair<let, let>> players;
    for (let i = 1; i <= N; i++)
    {
      players.pb({__gcd(i, N), i});
    }
    sort(all(players), [&](pair<let, let> a, pair<let, let> b)
         {
           if (a.ff == b.ff) return a.ss < b.ss;
           return a.ff > b.ff;
         });
    for (auto &p : players)
      cout << p.ss << " ";
    cout << endl;
  }
  return 0;
}
