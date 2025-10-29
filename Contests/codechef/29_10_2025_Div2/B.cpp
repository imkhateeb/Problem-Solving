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
    let n; cin >> n;
    vector<let> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<let> temp = v;
    sort(temp.begin(), temp.end());

    unordered_map<let, let> mp;

    mp[temp[0]] = -1;
    mp[temp[n-1]] = -1;

    for(int i = 1; i < n-1; i++){
      let first = (temp[i] + temp[i-1])/2;
      let second = (temp[i+1] + temp[i])/2;
      mp[temp[i]] = second - first;
    }

    for(auto it : v){
      cout << mp[it] << " ";
    }cout << endl;
  }

  return 0;
}