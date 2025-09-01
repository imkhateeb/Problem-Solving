#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void solve() {
    int n;
    cin >> n;

    if(n%2) {
        cout << (n+1)/2 << endl;
    }else{
        int half = n/2;
        int odds = (n-half)/2;
        cout << n - odds << endl;
    }
    
}

signed main() {
    FAST
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
