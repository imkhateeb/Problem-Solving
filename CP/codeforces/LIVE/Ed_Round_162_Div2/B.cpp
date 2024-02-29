#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<long long> arr(n+1, 0);

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int p = abs(x);
            arr[p] += a[i];
        }

        long long bullet = k;
        bool flag = true;

        for (int i = 1; i <= n; ++i) {
            bullet -= arr[i];
            if (bullet < 0) {
                flag = false;
                cout << "NO" << endl;
                break;
            }
            bullet += k;
        }

        if (flag) {
            cout << "YES" << endl;
        }
    }

    return 0;
}