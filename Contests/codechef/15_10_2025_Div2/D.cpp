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
  int t;
    cin >> t;
    
    while( t-- ){
        let n, c;
        cin >> n >> c;

        vi b(n);
        vi d(n);

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        for(int i = 0; i < n; i++){
            cin >> d[i];
        }

        let maxIdx = -1;
        let maxValue = LLONG_MIN;
        for(int i = 0; i < n; i++){
            let minCost = INT_MAX;
            for(int j = 0; j < n; j++){

                let cost = d[i] * 1LL * b[j];
                let rotCost = 0;
                if(j >= i){
                    rotCost += (c * 1LL * (j - i));
                }else{
                    rotCost += ((n-j+i) * c);
                }
                cost += rotCost;
                if(minCost > cost){
                    minCost = cost;
                }
            }

            if(minCost > maxValue){
                maxValue = minCost;
                minIdx = i;
            }
        }

        let totalCost = maxValue;
        for(int i = 0; i < n; i++){
            if(i != minIdx){
                totalCost += (cost * 1LL * b[i]);
            }
        }

        cout << totalCost << endl;
    }
    return 0;
}