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

        bool flag = false;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x!=1) flag = true;
        }

        if(flag){
            cout << 499122177 << endl;
        }else{
            if(n%2 == 0){
                cout << 0 << endl;
            }else{
                cout << 998244354 << endl;
            }
        }
    }
    
    return 0;
}