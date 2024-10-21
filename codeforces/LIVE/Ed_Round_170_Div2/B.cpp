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

long long powerof2WithMOD(int q)
{
  long long ans = 1;
  for (int i = 0; i < q; i++)
  {
    ans = (ans * 2) % MOD;
  }
  return ans;
}

int main()
{

  let T;
  cin >> T;
  vector<int> p(T), q(T);
  for (int i = 0; i < T; i++)
  {
    cin >> p[i];
  }
  for (int i = 0; i < T; i++)
  {
    cin >> q[i];
  }

  for (int i = 0; i < T; i++)
  {
    cout << powerof2WithMOD(q[i]) << endl;
  }

  return 0;
}