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
    string s; cin >> s;

    if(s[0] == '0' || s[n-1] == '0'){
      cout << -1 << endl;
      continue;
    }

    stack<int> st;
    for(int i = 0; i < n; i++){
      if(s[i] == '1'){
        cout << i + 1 << " ";
        while(!st.empty()){
          cout << st.top() << " ";
          st.pop();
        }
      }else{
        st.push(i + 1);
      }
    }
    while(!st.empty()){
      cout << st.top() << " ";
      st.pop();
    }
    cout << endl;
  }

  return 0;
}