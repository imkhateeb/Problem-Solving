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
    let maxi = LLONG_MIN;
    vi v(n);
    unordered_map<let, int> present;
    for(int i = 0; i < n; i++) {
      let x; cin >> x;
      present[x]++;
      v[i] = x;
      if (x > maxi) maxi = x;
    }

    let p = 0;
    let q = 0;

    for(int i = 0; i < n; i++){
      if(v[i] == maxi){
        p++;
      }else if(v[i] == maxi - 1){
        q++;
      }
    }
    
    if(present[maxi] > 1) {
        cout << maxi - 1 << endl;
    }else{
      if(p+q != n){
        cout << maxi - 1 << endl;
      }else{
        cout << maxi - 2 << endl;
      }
    }
  }

  return 0;
}