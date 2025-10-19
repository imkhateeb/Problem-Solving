#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<let>
#define vvi vector<vector<let>>
#define vs vector<string>
#define vpii vector<pair<let, let>>
using namespace std;

bool canVisitAll(vector<long long>& A, long long h) {
    int n = A.size();
    vector<bool> visited(n, false);
    
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (A[i] <= h) {
            q.push(i);
            visited[i] = true;
        }
    }
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr > 0 && !visited[curr - 1]) {
            if (abs(A[curr] - A[curr - 1]) <= h) {
                visited[curr - 1] = true;
                q.push(curr - 1);
            }
        }
        
        if (curr < n - 1 && !visited[curr + 1]) {
            if (abs(A[curr] - A[curr + 1]) <= h) {
                visited[curr + 1] = true;
                q.push(curr + 1);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

long long findMinLadder(vector<long long>& A) {
    int n = A.size();
    
    long long left = 0, right = 2e9;
    long long result = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canVisitAll(A, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        long long answer = findMinLadder(A);
        cout << "Case #" << tc << ": " << answer << endl;
    }
    
    return 0;
}