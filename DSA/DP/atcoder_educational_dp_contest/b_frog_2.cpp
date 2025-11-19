#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k; cin >> n >> k;
    vector<int>h(n, 0);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int>dp(k, 0);

    for(int i = 1; i < n; i++){
        int mini = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i - j < 0) break;
            mini = min(mini, abs(h[i-j] - h[i]) + dp[k-j]);
        }
        for(int j = 0; j < k-1; j++){
            dp[j] = dp[j+1];
        }
        dp[k-1] = mini;
    }

    cout << dp[k-1] << endl;

    return 0;
}