#include <bits/stdc++.h>
using namespace std;
#define int long long
#define enl "\n"
#define all(x) x.begin(), x.end()
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int N = 2e6 + 19;
const int Mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++){
        for(int j = i; j < n-i; j++){
            cout << j << " ";
        }
        for(int j = 0; j <= i-1; j++){
            cout << j << " ";
        }
        cout << endl;
    }

}

signed main()
{
    FAST

    int T = 1;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        // cout << "Case " << tt << ": ";
        solve();
    }
    return 0;
}