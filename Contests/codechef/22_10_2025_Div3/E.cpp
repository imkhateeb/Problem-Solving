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
    let T;
    cin >> T;
    while (T--) {
        let n, m; 
        cin >> n >> m;

        map<let, let, greater<let>> a;
        map<let, let, greater<let>> b;

        for (let i = 0; i < n; i++) {
            let x; cin >> x;
            a[x]++;
        }
        for (let i = 0; i < m; i++) {
            let x; cin >> x;
            b[x]++;
        }

        let sum = 0;

        for (auto it : a) {
            let acnt = it.second;
            let bcnt = 0;

            for (auto itt = b.begin(); itt != b.end();) {
                if (itt->first == it.first) {
                    ++itt;
                    continue;
                }

                bcnt += itt->second;

                if (bcnt <= acnt) {
                    sum += (itt->first * 1LL * itt->second);
                    itt = b.erase(itt);
                } else {
                    let diff = bcnt - acnt;
                    sum += (itt->first * 1LL * (itt->second - diff));
                    if(diff == 0) b.erase(itt);
                    else b[itt->first] = diff;
                    break;
                }
            }

            if (bcnt >= acnt) {
                sum += (it.first * 1LL * acnt);
            } else {
                sum += (it.first * 1LL * bcnt);
            }
        }

        cout << sum << endl;
    }

    return 0;
}
