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

    int n; cin >> n;
    vector<int> v(n);
    bool odd = false;
    bool even = false;

    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      v[i] = x;

      if(x%2 == 0) {
        even = true;
      }else{
        odd = true;
      }
    }

    if(even && odd){
      sort(v.begin(), v.end());
    }

    for(auto it : v) cout << it << " ";
    cout << endl;
    
  }

  return 0;
}