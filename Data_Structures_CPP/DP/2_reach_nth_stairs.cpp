#include <bits/stdc++.h>
using namespace std;

int findWays(int nStairs, vector<int> &dp, int currStair) {
    // Base Cases
    if (currStair == nStairs) {
        return 1;
    }
    if (currStair > nStairs) {
        return 0;
    }

    // Look Up
    if (dp[currStair] != -1) {
        return dp[currStair];
    }

    // Recursive Case
    dp[currStair] = (findWays(nStairs, dp, currStair + 1) + findWays(nStairs, dp, currStair + 2)) % 1000000007;
    return dp[currStair];
}

int main() {
    int nStairs;
    cout << "Enter the number of stairs: ";
    cin >> nStairs;

    vector<int> dp(nStairs + 1, -1);
    int ans = findWays(nStairs, dp, 0);
    
    // Output the result
    cout << "Number of ways to climb " << nStairs << " stairs: " << ans << endl;

    return 0;
}
