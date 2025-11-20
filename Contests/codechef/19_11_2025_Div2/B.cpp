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
    int n, x; cin >> n >> x;
    bool found = false;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
      int p; cin >> p;
      mini = min(mini, p);
      maxi = max(maxi, p);
      if(x == p){
        found = true;
      }
    }

    if(x <= mini || x >= maxi || found){
      cout << "Yes" << endl; 
    }else {
      cout << "No" << endl;
    }
  }

  return 0;
}