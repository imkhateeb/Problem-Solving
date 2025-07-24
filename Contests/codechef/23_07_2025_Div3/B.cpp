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

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    int maxi = INT_MIN;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[i] = x;
      maxi = max(maxi, x);
    }

    int maxAns = INT_MIN;

    for(int l = 0; l <= maxi; l++){

      int sum = 0;

      for(int i = 0; i < n; i++){
        if(b[i] <= l && a[i] > 0){
          sum += a[i];
        }
      }

      maxAns = max(maxAns, sum - l);

    }

    cout << maxAns << endl;

  }

  return 0;
}
