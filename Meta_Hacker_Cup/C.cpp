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
  for(int tc = 1; tc <= T; tc++){

    int n, a, b;
    cin >> n >> a >> b;

    cout << "Case #" << tc << ": ";
    for(int i = 0; i < (2*n - 1); i++){
        cout << 1 << " ";
    }
    cout << b << endl;

  }

  return 0;
}