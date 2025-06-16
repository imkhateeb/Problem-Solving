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

pair<int, int> findPairWithProduct(let x, const vi &arr)
{
  unordered_set<let> seen;

  for (let num : arr)
  {
    if (num != 0 && x % num == 0)
    {
      let complement = x / num;
      if (seen.count(complement))
      {
        return {num, complement};
      }
    }
    seen.insert(num);
  }
  return {-1, -1};
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let k;
    cin >> k;
    vi arr(k);
    int cnt = 0;
    for (let i = 0; i < k; i++)
    {
      cin >> arr[i];
      cnt++;
    }

    pair<int, int> result = findPairWithProduct(cnt - 2, arr);

    cout << result.ff << " " << result.ss << endl;
  }
  return 0;
}
