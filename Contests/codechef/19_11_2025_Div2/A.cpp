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
    int o = 0;
    int t = 0;
    int th = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1) o++;
        else if(x == 2) t++;
        else th++;
    }

    int deleted = 0;
    if(o > th){
        deleted += th;
    }else{
        deleted += o;
    }
    if(t > 0){
        deleted += (t - 1);
    }

    cout << deleted << endl;
  }

  return 0;
}