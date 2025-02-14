#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> find_min_rotation(const vector<ll> &arr, ll m)
{
  vector<ll> extended(arr.begin(), arr.end());
  extended.insert(extended.end(), arr.begin(), arr.end());

  ll min_pos = 0;
  for (ll i = 1; i < m; i++)
  {
    ll j = 0;
    while (j < m && extended[i + j] == extended[min_pos + j])
      j++;
    if (j < m && extended[i + j] < extended[min_pos + j])
      min_pos = i;
  }
  return vector<ll>(extended.begin() + min_pos, extended.begin() + min_pos + m);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll T;
  cin >> T;

  while (T--)
  {
    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll &x : A)
      cin >> x;

    vector<ll> B(m);
    for (ll i = 0; i < m; i++)
      cin >> B[i];

    vector<ll> lexsr = find_min_rotation(B, m);

    for (int i = 0; i < (n - m); i++)
    {
      if (A[i] >= lexsr[0])
      {
        for (int j = 0; j < m; j++)
        {
          A[i + j] = lexsr[0];
        }
        i = i + m - 1;
      }
      else
      {
        break;
      }
    }
  }
  return 0;
}