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

let max(let a, let b){
  if(a > b) return a;
  return b;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  let T;
  cin >> T;
  while (T--)
  {
    let n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    let lo = 1, hi = n, ans = 1;

    while (lo <= hi)
    {
      int mid = (lo + hi)/2;

      int t1 = 0;
      int t0 = 0;
      int cnt1 = 0;
      int last1 = 0;

      for(int i = 0; i < n; i++){
        if(s[i] == '0'){
          t0++;
          last1 = 0;
        }else if(s[i] == '1'){
          t1++;
          last1++;
        }

        if(t1 >= mid || ((t0 + last1) >= mid)){
          cnt1++;
          t1 = 0;
          t0 = 0;
          last1 = 0;
        }
      }

      t1 = 0;
      t0 = 0;
      int cnt2 = 0;
      int last0 = 0;

      for(int i = n-1; i >= 0; i--){
        if(s[i] == '0'){
          t0++;
          last0++;
        }else if(s[i] == '1'){
          t1++;
          last0 = 0;
        }

        if(t0 >= mid || ((t1 + last0) >= mid)){
          cnt2++;
          t1 = 0;
          t0 = 0;
          last0 = 0;
        }
      }

      int cnt = max(cnt1, cnt2);

      if(cnt >= k){
        ans = max(ans, mid);
        lo = mid + 1;
      }else{
        hi = mid - 1;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
