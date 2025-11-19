#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }

    vector<int> prev(3), curr(3);
    prev[0] = v[n-1][0];
    prev[1] = v[n-1][1];
    prev[2] = v[n-1][2];

    for(int i = n-2; i >= 0; i--){
        curr[0] = max(prev[1], prev[2]) + v[i][0];
        curr[1] = max(prev[0], prev[2]) + v[i][1];
        curr[2] = max(prev[1], prev[0]) + v[i][2];

        prev = curr;
    }

    cout << *max_element(prev.begin(), prev.end()) << endl;


    return 0;
}