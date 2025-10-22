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
    int x, y; cin >> x >> y;

    int even = 0;
    int odd = 0;

    for(int i = x; i <= y; i++){
        if(i%x == 0){
            if(i%2 == 0) even += i;
            else odd += i;
        }
    }

    if(even >= odd){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
  }

  return 0;
}