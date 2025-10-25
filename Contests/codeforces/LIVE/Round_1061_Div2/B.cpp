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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    bool found = false;
    for(auto ch : s){
        if(ch == 'B'){
            found = true;
            break;
        }
    }

    while(q--){
        int x; cin >> x;
        if(found){
        int ind = 0;
        int temp = x;
        while(true){
            if(temp == 0){
                cout << ind << endl;
                break;
            }
            if(s[ind%n] == 'A'){
                temp = temp - 1;
            }else{
                temp = temp/2;
            }
            ind++;
        }
    }else{
        cout << x << endl;
    }

    }



    
  }

  return 0;
}