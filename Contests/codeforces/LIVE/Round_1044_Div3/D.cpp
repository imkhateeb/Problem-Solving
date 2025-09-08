#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
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
    let n;
    cin >> n;

    unordered_map<let, let> mp;
    vector<let> v(n);

    for(int i = 0; i < n; i++){
        let x;
        cin >> x;
        v[i] = x;
        mp[x]++;
    }

    bool flag = false;

    for(auto it: mp){
        if(it.second % it.first != 0){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << -1 << endl;
        continue;
    }

    let curr = 1;

    unordered_map<let, multiset<let>> mp1;

    for(auto it: mp){
        let x = it.first;
        let y = it.second;

        let round = y/x;

        while(round--){
            for(int i = 0; i < x; i++){
                mp1[x].insert(curr);
            }
            curr++;
        }
    }

    for(auto num : v){
        auto it = mp1[num].begin();
        let p = *it;
        mp1[num].erase(it);
        cout << p << " ";
    }cout << endl;
  }

  return 0;
}