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
    let n, k; cin >> n >> k;
    string s; cin >> s;

    char fni = '$';
    char lni = '$';
    int idx = -1;

    for(int i = 0; i < n; i++){
      char ch = s[i];
      if(ch != 'I'){
        if(fni == '$'){
          idx = i;
          fni = ch;
        }else{
          lni = ch;
        }
      }
    }

    let total = 0;

    if(idx == -1){
      cout << (((n-1) * 1LL * k) + (k-1)) << endl;
      continue;
    }

    char last = s[idx];
    int cnt = 1;
    int j = idx;
    for(int i = idx+1; i < n; i++){
      if(s[i] == 'I'){
        j++;
        continue;
      }
      if(s[i] == last){
        cnt++;
      }else{
        total += (cnt + j - 1);
        cnt = 1;
        j = 0;
        last = s[i];
      }
    }
    total += (cnt + j - 1);

    // cout << "TOTAL: " << total << endl;

    total = total * 1LL * k;

    if(fni == '$' || lni == '$' || lni == fni){
      total += (k - 1);
    }

    cout << total << endl;
  }

  return 0;
}