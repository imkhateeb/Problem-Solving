#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int r_wt, 
    unordered_map<int, unordered_map<int, int>> dp, 
    vector<pair<int, int>> v)
{
    if(idx == 0){
        int canTake = r_wt/v[idx].first;
        return canTake * v[idx].second;
    }

    if(dp[r_wt][idx] != 0) return dp[r_wt][idx];

    int notTake = solve(idx-1, r_wt, dp, v);
    int take = 0;
    if(r_wt >= v[idx].first){
        take = v[idx].second + solve(idx-1, r_wt - v[idx].first, dp, v);
    }

    return dp[r_wt][idx] = max(take, notTake);

}

int main(){

    int n, w; cin >> n >> w;
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }

    unordered_map<int, unordered_map<int, int>> dp;

    int maxValue = solve(n-1, w, dp, v);
    cout << maxValue << endl;

    return 0;
}