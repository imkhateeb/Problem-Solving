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
    let n; cin >> n;

    vector<let> v(n);

    for(let i = 0; i < n; i++) cin >> v[i];

    if(n <= 2){

      if(v[0] > v[1]){
        cout << v[0] - v[1] << endl;
      }

    }

    int p = -1, q = -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i=i+2){
      if(v[i] >= maxi){
        p = i;
        maxi = v[i];
      }
    }

    for(int i = 1; i < n; i=i+2){
      if(v[i] < mini){
        q = i;
        mini = v[i]; 
      }
    }

    bool unswappable = maxi >= mini;

    if(unswappable){

      sort(v.begin(), v.end()){

      }

    }else{

    }

    cout << ans << endl;
  }

  return 0;
}