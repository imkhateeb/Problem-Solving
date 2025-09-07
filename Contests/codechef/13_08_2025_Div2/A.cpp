#include <bits/stdc++.h>
using namespace std;
#define int long long
#define enl "\n"
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;

    vector<int> v;
    int ones = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) ones++;
        else v.push_back(x);
    }

    int maxi = 0;
    if (!v.empty()) {
        sort(v.begin(), v.end());
        int cnt = 1;
        for (int i = 0; i + 1 < (int)v.size(); i++) {
            if (v[i] == v[i + 1]) cnt++;
            else {
                maxi = max(maxi, cnt);
                cnt = 1;
            }
        }
        maxi = max(maxi, cnt);
    }

    if (ones >= maxi) {
        cout << n - maxi << enl;
    } else {
        cout << n - maxi - 1 << enl;
    }
}

signed main() {
    FAST
    int T;
    cin >> T;
    while (T--) solve();
}
