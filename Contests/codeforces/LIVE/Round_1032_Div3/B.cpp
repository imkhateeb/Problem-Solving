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
    string s;
    cin >> s;

    char first = s[0];
    char last = s[n -1];
    bool found = false;
    unordered_map<char, bool> mp;

    for(int i = 1; i < n-1; i++){
      if(s[i] == first || s[i] == last){
        cout << "Yes" << endl;
        found = true;
        break;
      }else{
        if(mp[s[i]]){
          cout << "Yes" << endl;
          found = true;
          break;
        }else{
          mp[s[i]] = true;
        }
      }
    }
    if(!found){
      cout << "No" << endl;
    }
  }

  return 0;
}