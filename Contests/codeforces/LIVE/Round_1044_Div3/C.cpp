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

bool isEven(let a) {
    return a%2 == 0;
}

bool isOdd(let a){
    return a%2 == 1;
} 

int main()
{
  let T;
  cin >> T;
  while (T--)
  {

    let a, b;
    cin >> a >> b;

    if((isEven(a) && isOdd(b)) || (isEven(b) && isOdd(a) && isOdd(b/2))){
        cout << -1 << endl;
    }else{
        if(isEven(a) && isEven(b)){
            let multiplier = b/2;
            cout << a*multiplier + 2 << endl;
        }else if(isOdd(a) && isOdd(b)){
            cout << a * b + 1 << endl;
        } else {
            let multiplier = b/2;
            cout << a*multiplier + 2 << endl;
        }
    }
  }

  return 0;
}