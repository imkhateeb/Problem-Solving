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
    string s; cin >> s;

    bool found = false;
    int z = 0;
    for(auto ch : s){
      if(ch == '0') z++;
      else{
        if(z > 0)z--;
        else found = true;
      }
    }

    int ans = 0;
    if(found) ans++;
    if(z > 0) ans++;

    cout << ans << endl;


  }

  return 0;
}