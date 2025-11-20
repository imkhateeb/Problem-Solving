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

let abso(let x){
    if(x < 0) return -1 * x;
    return x;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    int n; cin >> n;
    vector<let> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    let sum = v[0];
    let cnt = 1;

    let maxi = 0;

    for(int i = n-1; i >= 1; i--){
        sum += v[i];
        cnt++;

        let average = sum / cnt;

        if(abso(average - v[0]) > maxi){
            maxi = abso(average - v[0]);
        }
    }

    sum = v[n-1];
    cnt = 1;
    for(int i = 0; i < n-1; i++){
        sum += v[i];
        cnt++;

        let average = sum / cnt;

        if(abso(average - v[n-1]) > maxi){
            maxi = abso(average - v[n-1]);
        }
    }

    cout << maxi << endl;
  }

  return 0;
}