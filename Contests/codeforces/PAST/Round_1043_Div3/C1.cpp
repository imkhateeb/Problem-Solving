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
    let n;
    cin >> n;
 
    int i = 0;
 
    while(pow(3, i) <= n){
      i++;
    }
 
    i--;
 
    let ans = 0;
 
    while(n > 0){
      let power = pow(3, i);
      int x = n/power;
 
      ans += (x * (pow(3, i + 1) + i * 1LL * pow(3, i - 1)));
 
      i--;
      n = (n - x*power);
    }
 
    cout << ans << endl;
  }
 
  return 0;
}