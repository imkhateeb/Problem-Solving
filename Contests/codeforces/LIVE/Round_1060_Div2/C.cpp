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

vector<int> primes;

vector<int> sieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++)
        if (isPrime[i])
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
    vector<int> res;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i]) res.push_back(i);
    return res;
}

vector<int> getUniquePrimeFactors(int n) {
    vector<int> res;
    for (int p : primes) {
        if ((long long)p * p > n) break;
        if (n % p == 0) {
            res.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

bool addFactors(int n, unordered_map<int, int> &mp) {
    vector<int> f = getUniquePrimeFactors(n);
    for (int p : f) {
        mp[p]++;
        if (mp[p] > 1) return true;
    }
    return false;
}

void removeFactors(int n, unordered_map<int, int> &mp) {
    vector<int> f = getUniquePrimeFactors(n);
    for (int p : f) mp[p]--;
}

int main() {
    let T;
    cin >> T;

    primes = sieve(1000000);

    while (T--) {
        int n; 
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int, int> mp;
        int evens = count_if(a.begin(), a.end(), [](int x){ return x % 2 == 0; });
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (addFactors(a[i], mp)) {
                cout << 0 << endl;
                flag = true;
                break;
            }
        }

        if (flag) continue;

        for (int i = 0; i < n; i++) {
            removeFactors(a[i], mp);
            if (addFactors(a[i] + 1, mp)) {
                cout << 1 << endl;
                flag = true;
                break;
            }
            removeFactors(a[i] + 1, mp);
            addFactors(a[i], mp);
        }

        if (!flag) {
            if (evens >= 2) cout << 0 << endl;
            else if (evens == 1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }

    return 0;
}
