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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int lastOne = -1;
    int pr = 0;

    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(ch == '1'){
            if(lastOne == -1 && i < k-1){
                pr++;
            }else{
                if(lastOne < (i - (k - 1))){
                    pr++;
                }
            }
            lastOne = i;
        }
    }

    cout << pr << endl;
  }

  return 0;
}