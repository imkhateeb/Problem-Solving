#include <bits/stdc++.h>
using namespace std;
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

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    set<int> nt;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            nt.insert(a[i]);
        }
    }

    int min1 = 0;

    while(nt.find(min1) != nt.end()){
        min1++;
    }

    bool flag = false;

    for(int i = 0; i < n; i++){
        if(a[i] == min1){
            flag = true;
            break;
        }
    }

    if(flag){
        nt.insert(min1);
    }

    int min2 = 0;

    while(nt.find(min2) != nt.end()){
        min2++;
    }

    cout << max(min1, min2) << endl;
}

signed main()
{
    FAST
    int T = 1;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        solve();
    }
    return 0;
}
