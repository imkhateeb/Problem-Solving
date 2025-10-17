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
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for(int i = 0; i < n; i++){
      minHeap.push({v[i], i+1});
    }

    vector<int> p(n, -1);

    for(int i = 0; i < n; i++){
      if(minHeap.empty()) break;
      pair<int, int> top = minHeap.top();

      if(v[i] >= top.first){
        while(!minHeap.empty() && top.second == i + 1){
          minHeap.pop();
          top = minHeap.top();
        }
        p[i] = top.second;
        minHeap.pop();
      }
    }
    
    set<int> st;
    set<int> st2;

    for(int i = 0; i < n; i++){
      if(p[i] == -1){
        st.insert(i);
      }else{
        st2.insert(p[i]);
      }
    }

    

    int finalAns = n - st.size();

    cout << finalAns << endl;
    for(auto it : p){
      cout << it << " ";
    }cout << endl;
  
  }

  return 0;
}