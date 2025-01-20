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
    let n, k;
    cin >> n >> k;

    vi a(n);
    unordered_map<let, let> freq;

    for (let i = 0; i < n; i++)
    {
      cin >> a[i];
      freq[a[i]]++;
    }

    let ans = 0;

    for (let i = 0; i < n; i++)
    {
      let x = a[i];
      if (freq[x] == 0)
        continue;

      let y = k - x;
      if (freq[y] > 0 && (x != y || freq[x] > 1))
      {
        ans++;
        freq[x]--;
        freq[y]--;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
