#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> jars(N);
        for (int i = 0; i < N; ++i) {
            cin >> jars[i];
        }

        // Sort the jars in non-decreasing order
        sort(jars.begin(), jars.end());

        // Calculate the total number of cookies
        long long total_cookies = 0;
        for (int i = 0; i < N; ++i) {
            total_cookies += jars[i];
        }

        // Calculate the minimum number of wasted cookies
        long long min_wasted_cookies = -1;
        for (int i = N - 1; i >= 0; --i) {
            long long required_cookies = (long long)K * (N - i);
            if (total_cookies - jars[i] >= required_cookies) {
                min_wasted_cookies = total_cookies - required_cookies;
                break;
            }
        }

        cout << min_wasted_cookies << endl;
    }

    return 0;
}
