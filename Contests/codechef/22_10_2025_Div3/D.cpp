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
    string s; cin >> s;
    int c01 = 0;
    int c10 = 0;

    for(int i = 0; i < n-1; i++){
      if(s[i] == '0' && s[i+1] == '1'){
          c01++;
      }else if(s[i] == '1' && s[i+1] == '0'){
          c10++;
      }
    }

    if(c01 > 0 && c10 > 0){
      cout << "Alice" << endl;
    }else{
      cout << "Bob" << endl;
    }
  }

  return 0;
}