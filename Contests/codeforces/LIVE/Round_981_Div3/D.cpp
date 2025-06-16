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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  let t;
  cin >> t;

  while (t--)
  {
    let n;
    cin >> n;
    vi a(n);

    for (let i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    unordered_map<let, let> prefix_map;
    let prefix_sum = 0;
    let count_segments = 0;
    let last_reset_index = -1;

    prefix_map[0] = -1;

    for (let i = 0; i < n; i++)
    {
      prefix_sum += a[i];

      if (prefix_map.count(prefix_sum))
      {
        if (prefix_map[prefix_sum] >= last_reset_index)
        {
          count_segments++;
          last_reset_index = i;
        }
      }

      prefix_map[prefix_sum] = i;
    }

    cout << count_segments << endl;
  }

  return 0;
}
