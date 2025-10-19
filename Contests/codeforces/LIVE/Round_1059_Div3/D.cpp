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

int solve(int st, int en, let p, let a, bool& breakNow) {
    if (breakNow) return 1;
    if (st == en) {
        if (p != a) return st;
        return -1;
    }

    if (st > en) return -1;
    if (p == a) return -1;

    int mid = st + (en - st) / 2;

    cout << "1 " << st << " " << mid << endl;
    cout.flush();
    let stp; cin >> stp;

    cout << "2 " << st << " " << mid << endl;
    cout.flush();
    let sta; cin >> sta;

    let enp = p - stp;
    let ena = a - sta;

    int left = solve(st, mid, stp, sta, breakNow);
    if (breakNow) return 1;
    int right = solve(mid + 1, en, enp, ena, breakNow);
    if (breakNow) return 1;

    if (left == -1) return right;
    if (right == -1) return left;

    if (left != -1 && right != -1) {
        breakNow = true;
        cout << "! " << left << " " << right << endl;
        cout.flush();
        return 1;
    }

    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        cout << "1 1 " << n << endl;
        cout.flush();
        let p; cin >> p;

        cout << "2 1 " << n << endl;
        cout.flush();
        let a; cin >> a;

        bool breakNow = false;
        int result = solve(1, n, p, a, breakNow);
        
        // If we never found the answer, we need to handle it
        // (though according to problem constraints, answer should always exist)
        if (!breakNow) {
            // This shouldn't happen if problem guarantees a solution exists
            // But if it does, you need to print something to avoid idleness
            cout << "! -1 -1" << endl;  // or handle appropriately
            cout.flush();
        }
    }
    return 0;
}