#include <bits/stdc++.h>
#define let long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    let T;
    cin >> T;
    while (T--) {

        let n, a;
        cin >> n >> a;

        vector<let> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<let> L, R;
        for (let x : v) {
            let mid = (a + x) / 2;
            if (x < a) L.push_back(mid);
            else if (x > a) R.push_back(mid);
        }

        sort(L.begin(), L.end());
        sort(R.begin(), R.end());

        vector<let> cand;

        for (let x : L) {
            cand.push_back(x);
            cand.push_back(x - 1);
            cand.push_back(x + 1);
        }
        for (let x : R) {
            cand.push_back(x);
            cand.push_back(x - 1);
            cand.push_back(x + 1);
        }

        cand.push_back(a - 1);
        cand.push_back(a + 1);

        let best_b = 0, best_score = -1;

        for (let b : cand) {
            if (b < 0 || b > 2000000000) continue;

            let cnt = 0;
            cnt += (L.end() - upper_bound(L.begin(), L.end(), b));
            cnt += (lower_bound(R.begin(), R.end(), b) - R.begin());

            if (cnt > best_score) {
                best_score = cnt;
                best_b = b;
            }
        }

        cout << best_b << "\n";
    }

    return 0;
}
