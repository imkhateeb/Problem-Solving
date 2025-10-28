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

bool isPossible(int m, vector<int> &v, int l, int h, int k){
  if(m == 0) return true;
  
  int n = v.size();
  int init = (v[0] - 0)/m;
  int fin = (h - v[n-1])/m;
  int cnt = init + fin;
  
  int curr = 0;
  l = v[0];
  curr++;
  while(curr < n && h >= l){
    if(v[curr] - l >= 2 * m){
      cnt++;
      l += m;
    }else{
      l = v[curr];
      curr++;
    }
    if(cnt >= k) return true;
  }
  if(cnt >= k) return true;
  return false;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int low = 0;
    int high = x;
    int minD = 1;
    while(high >= low){
      int mid = (low + high)/2;
      if(isPossible(mid, v, 0, x, k)){
        minD = mid;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }

    if(minD == 0){
      for(auto it : v) cout << it << " ";
      cout << endl;
      continue;
    }

    int cnt = 0;
    int curr = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
      while(v[i] - curr >= 2 * minD){
        curr += minD;
        cout << curr << " ";
        cnt++;
        if(cnt == k) {
          flag = true;
          break;
        }
      }
      if(flag) break;
      curr = v[i];
    }
    while(cnt < k){
      curr += minD;
      cout << curr << " ";
      cnt++;
    }
    cout << endl;
  }
  return 0;
}