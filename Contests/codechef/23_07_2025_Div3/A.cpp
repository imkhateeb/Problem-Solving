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
    int n, c;
    cin >> n >> c;

    unordered_map<int, int> mp;

    int mini = INT_MAX;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        mini = min(mini, x);
    }

    int cnt = 0;
    while(c < mini || mp[c] != 0){
        c++;
        cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}
