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
  int t;
    cin >> t;
    
    while( t-- ){
        int n, x, k;
        cin >> n >> x >> k;
        
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        
        int p = x + (k * 100);

        int cnt = 0;
        for(auto it : v){
            if(it > p) cnt++;
        }
        
        if(cnt >= k){
            cout << cnt - k + 1 << endl;
        }else{
            cout << 1 << endl;
        }
    }
    return 0;
}