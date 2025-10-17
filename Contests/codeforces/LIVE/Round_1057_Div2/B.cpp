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
    int T; cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        bool ok = true;
        for (int i = 0; i < 31; i++) {
            int xi = (x >> i) & 1;
            int yi = (y >> i) & 1;
            int zi = (z >> i) & 1;
            if (!(
                (xi==0 && yi==0 && zi==0) ||
                (xi==0 && yi==0 && zi==1) ||
                (xi==0 && yi==1 && zi==0) ||
                (xi==1 && yi==0 && zi==0) ||
                (xi==1 && yi==1 && zi==1)
            )) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
