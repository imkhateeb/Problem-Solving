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
    set<let> st;
    for(auto i = 0; i < n; i++){
        let x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << endl;
  }

  return 0;
}