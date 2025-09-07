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
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int initial = (a1 * 5) + b1;
    int finals = (a2 * 5) + b2;

    while(initial > finals){
        initial -= 6;
    }

    if(initial == finals){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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