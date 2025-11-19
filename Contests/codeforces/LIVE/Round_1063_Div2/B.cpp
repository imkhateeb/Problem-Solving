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


int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        
        string x;
        cin >> x;
        
        vector<int> required;
        for (int i = 0; i < n; i++) {
            if (x[i] == '1') {
                required.push_back(i + 1);
            }
        }
        
        if (required.empty()) {
            cout << 0 << "\n";
            continue;
        }
        
        vector<pair<int, int>> operations;
        set<int> covered;
        
        int min_val = min(p[1], p[n]);
        int max_val = max(p[1], p[n]);
        for (int i = 2; i < n; i++) {
            if (min_val < p[i] && p[i] < max_val) {
                covered.insert(i);
            }
        }
        
        bool all_covered = true;
        for (int pos : required) {
            if (!covered.count(pos)) {
                all_covered = false;
                break;
            }
        }
        
        if (all_covered) {
            cout << 1 << "\n";
            cout << 1 << " " << n << "\n";
            continue;
        }
        
        operations.clear();
        covered.clear();
        
        for (int pos : required) {
            if (covered.count(pos)) continue;
            
            int best_l = -1, best_r = -1;
            
            for (int l = 1; l < pos; l++) {
                for (int r = pos + 1; r <= n; r++) {
                    int min_val = min(p[l], p[r]);
                    int max_val = max(p[l], p[r]);
                    
                    if (min_val < p[pos] && p[pos] < max_val) {
                        best_l = l;
                        best_r = r;
                        break;
                    }
                }
                if (best_l != -1) break;
            }
            
            if (best_l == -1) {
                cout << -1 << "\n";
                goto next_test;
            }
            
            operations.push_back({best_l, best_r});
            
            int min_val = min(p[best_l], p[best_r]);
            int max_val = max(p[best_l], p[best_r]);
            for (int i = best_l + 1; i < best_r; i++) {
                if (min_val < p[i] && p[i] < max_val) {
                    covered.insert(i);
                }
            }
            
            if (operations.size() > 5) {
                cout << -1 << "\n";
                goto next_test;
            }
        }
        
        cout << operations.size() << "\n";
        for (auto [l, r] : operations) {
            cout << l << " " << r << "\n";
        }
        
        next_test:;
    }
    
    return 0;
}