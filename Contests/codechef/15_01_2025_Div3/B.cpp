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

let countSetBits(let n)
{
  let count = 0;
  while (n > 0)
  {
    count += (n & 1);
    n >>= 1;
  }
  return count;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    vi perm(n + 1);
    for (let i = 1; i <= n; i++)
    {
      cin >> perm[i];
    }

    vector<set<let>> positionGroups(n + 1);
    for (let i = 1; i <= n; i++)
    {
      positionGroups[countSetBits(i)].insert(i);
    }

    bool isMisplaced = false;
    for (let i = 1; i <= n; i++)
    {
      if (positionGroups[countSetBits(perm[i])].count(i) == 0)
      {
        isMisplaced = true;
        break;
      }
    }

    cout << (isMisplaced ? "No" : "Yes") << endl;
  }

  return 0;
}
