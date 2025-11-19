#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<int>h(n, 0);
    for(int i = 0; i < n; i++) cin >> h[i];

    int l = 0;
    int r = abs(h[1] - h[0]);

    for(int i = 2; i < n; i++){
        int fromR = abs(h[i] - h[i-1]) + r;
        int fromL = abs(h[i] - h[i-2]) + l;

        l = r;
        r = min(fromR, fromL);
    }

    cout << r << endl;

    return 0;
}