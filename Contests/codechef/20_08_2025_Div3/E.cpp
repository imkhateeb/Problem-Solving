#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        int i = 1;

        while(i <= n){
            ans = ans | i;
            i++;
        }
        cout << ans << endl;
    }
    
    return 0;
}