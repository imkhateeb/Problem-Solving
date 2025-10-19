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

let maxx(let a, let b) {
    return (a > b) ? a : b;
}

int main() {
    let T;
    cin >> T;
    while (T--) {
        let n;
        cin >> n;
        vector<let> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        unordered_map<let, let> mp;
        for (auto it : v) {
            mp[it]++;
        }

        let sum = 0;
        let maximum = INT_MIN;

        vector<let> leftover;

        for (auto it : mp) {
          if (it.second % 2 == 0) {
              sum += 1LL * it.first * it.second;
              maximum = maxx(maximum, it.first);
          } else {
              sum += 1LL * it.first * (it.second - 1);
              if(it.second - 1 > 0){
                maximum = maxx(maximum, it.first);
              }
              leftover.push_back(it.first);
          }
        }

        if(leftover.size() <= 2){
          while(!leftover.empty()){
            let back = leftover.back();
            maximum = maxx(maximum, back);
            if(sum > maximum){
              sum += back;
            }
            leftover.pop_back();
          }
          cout << sum << endl;
        }else{

          let maxValidSum = 0;
          let ans = 0;

          let size = leftover.size();
          sort(leftover.begin(), leftover.end());

          for(let i = 0; i < size; i++){
            let curr = leftover[i];
            let candidate = -1;
            
            let st = i+1;
            let en = size-1;
            let mid = (st + en)/2;

            while(en >= st){
              if(sum + curr > leftover[mid]){
                candidate = mid;
                st = mid + 1;
              }else{
                en = mid - 1;
              }
              mid = (st + en)/2;
            }

            if(candidate == -1){
              if(sum > curr){
                if(curr > maxValidSum){
                  maxValidSum = curr;
                }
              }
            }else{
              if((curr + leftover[candidate]) > maxValidSum){
                maxValidSum = curr + leftover[candidate];
              }
            }
          }

          if(maxValidSum == 0){
            if(sum > 2 * 1LL * maximum){
              ans = sum;
            }
          }else{
            ans = sum + maxValidSum;
          }
          cout << ans << endl;
        }
    }

    return 0;
}
