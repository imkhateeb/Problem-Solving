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

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            int temp = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (abs(v[i] - v[j]) <= 1)
                {
                    ans = min(ans, temp);
                    break;
                }
                temp++;
            }
        }

        for(int i = 1; i < n-1; i++){
            if((v[i] <= v[i+1] && v[i] <= v[i-1]) || (v[i] >= v[i+1] && v[i] >= v[i-1])){
                ans = min(ans, 1);
                break;
            }
        }
        if(ans == INT_MAX){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}