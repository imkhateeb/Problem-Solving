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
    let a, b;
    cin >> a >> b;

    if(a == b){
        cout << 0 << endl;
    }else if(a%b == 0 || b%a == 0){
        cout << 1 << endl;
    }else {
        cout << 2 << endl;
    }
  }

  return 0;
}