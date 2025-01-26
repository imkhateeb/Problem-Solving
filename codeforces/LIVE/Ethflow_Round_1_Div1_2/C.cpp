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

map<vector<let>, let> memo;

let findSum(vi &a)
{
  let sum = 0;
  for (let i = 0; i < a.size(); i++)
  {
    sum += a[i];
  }
  return sum;
}

let maximizeSum(vi &a)
{
  if (a.size() == 1)
    return a[0];

  if (memo.find(a) != memo.end())
    return memo[a];

  let currentSum = findSum(a);

  vi temp1 = a;
  for (let i = 0; i < temp1.size() - 1; i++)
  {
    temp1[i] = temp1[i + 1] - temp1[i];
  }
  temp1.ppb();

  vi temp2 = a;
  reverse(all(temp2));
  for (let i = 0; i < temp2.size() - 1; i++)
  {
    temp2[i] = temp2[i + 1] - temp2[i];
  }
  temp2.ppb();

  let maxSum1 = maximizeSum(temp1);
  let maxSum2 = maximizeSum(temp2);

  return memo[a] = max({currentSum, maxSum1, maxSum2});
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    vi a(n);
    for (let i = 0; i < n; i++)
      cin >> a[i];

    memo.clear();
    let result = maximizeSum(a);
    cout << result << endl;
  }

  return 0;
}