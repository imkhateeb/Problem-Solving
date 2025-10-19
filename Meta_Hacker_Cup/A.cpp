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
  for (int tc = 1; tc <= T; tc++)
  {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    if(n == 1){
        cout << "Case #" << tc << ": " << 0 << endl;
        continue;
    }

    int minLength = INT_MIN;
    for(int i = 0; i < n-1; i++){
        minLength = max(minLength, abs(v[i] - v[i+1]));
    }

    cout << "Case #" << tc << ": " << minLength << endl;
  }

  return 0;
}