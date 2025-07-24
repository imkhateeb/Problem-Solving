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

    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    let sum = 0;

    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      minHeap.push(x);
      sum += x;
    }

    unordered_map<let, int> mp;

    while(k--){
      int num1 = minHeap.top();
      minHeap.pop();
      int num2 = minHeap.top();
      minHeap.push(num1);

      let temp = num1 + num2;
      int x;
      if(temp%2){
        x = (temp+1)/2;
      }else{
        x = temp/2;
      }
      minHeap.push(x);
      sum += x;
      mp[x]++;
      if(mp[x] >= 3){

        sum += (k * 1LL * x);
        break;

      }
    }

    cout << sum << endl;

  }

  return 0;
}
