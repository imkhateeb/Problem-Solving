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

    vector<int> v;
    for(int i = 0; i < s.size(); i++){
      char ch = s[i];
      if(ch == '1'){
        v.push_back(i);
      }
    }

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
      cout << v[i] + 1 << " ";
    }cout << endl;
  }

  return 0;
}