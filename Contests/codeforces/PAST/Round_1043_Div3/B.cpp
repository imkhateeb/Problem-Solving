#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
 
        vector<long long> v;
        long long temp = 1;
 
        for (int i = 0; i < 19; i++)
        {
            long long curr = temp * 10 + 1;
            if (n % curr == 0)
            {
                v.push_back(n / curr);
            }
            else if ((curr * (n * 1LL / curr)) > n)
            {
                break;
            }
            temp *= 10;
        }
 
        if (v.size() == 0)
        {
            cout << 0 << "\n";
            continue;
        }
 
        sort(v.begin(), v.end());
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}