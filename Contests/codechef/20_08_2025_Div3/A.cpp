#include <bits/stdc++.h>

using namespace std;

int main(){

        int n, x, y;
        cin >> n >> x >> y;

        int a = y/x;

        int ans = n/a;

        if(n%a != 0) ans++;

        cout << ans << endl;        
    


    return 0;
}