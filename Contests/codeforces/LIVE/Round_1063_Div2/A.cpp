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
  let T;
  cin >> T;
  while (T--)
  {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    bool flag = true;

    for(int i = 1; i < n-1; i += 2){
        if(v[i] != v[i+1]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl; 
    }else{
        cout << "NO" << endl;
    }
  }

  return 0;
}