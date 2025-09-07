#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        int m;
        cin >> n >> a >> m >> b;
        string x;
        cin >> x;
 
        string ans = a;
 
        for(int i=0;i<m;i++)
        {
            if(x[i] ==  'D'){
                ans = ans + b[i];
            }
            else{
                ans = b[i] + ans;
            }
        }
 
        cout << ans << "\n";
 
 
    }
    return 0;
}