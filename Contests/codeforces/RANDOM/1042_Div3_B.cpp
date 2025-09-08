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
    let n;
    cin >> n;


    let temp = n;
    if(temp%2 == 0) temp--;

    vector<let> a(n);

    for(int i = 0; i < temp; i = i + 2){
        a[i] = -1;
    }
    
    for(int i = 1; i < temp; i = i + 2){
        a[i] = 3;
    }

    if(n%2 == 0){
        a[n-1] = 2;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }cout << endl;
  }

  return 0;
}