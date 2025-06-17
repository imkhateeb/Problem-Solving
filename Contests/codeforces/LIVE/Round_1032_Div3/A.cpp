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
    let n, s;
    cin >> n >> s;

    let first;
    let last;
    for(int i = 0; i < n; i++){
        let x;
        cin >> x;
        if(i == 0) first = x;
        if(i == n-1) last = x;
    }

    if(s >= first && s <= last){
        cout << (min(s-first, last-s) + last-first) << endl;
    }else if(s < first){
        cout << last-s << endl;
    }else{
        cout << s-first << endl;
    }
  }

  return 0;
}