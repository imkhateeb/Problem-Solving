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
    let n, k;
    cin >> n >> k;
    priority_queue<let, vi, greater<let>> minHeap;
    for (let i = 0; i < n; i++)
    {
      let cans;
      cin >> cans;
      minHeap.push(cans);
    }

    let factor = 0;
    let buttonPresses = 0;
    let sum = 0;

    while (sum < k && minHeap.size() > 0)
    {
      let temp = minHeap.top();
      minHeap.pop();

      if (temp - factor == 0)
      {
        buttonPresses++;
        continue;
      }
      else
      {
        let x = temp - factor;
        let size = minHeap.size() + 1;

        if (x * size >= k - sum)
        {
          buttonPresses += k - sum;
          sum = k;
        }
        else
        {
          buttonPresses += x * size;
          sum += x * size;
          factor += x;
          buttonPresses++;
        }
      }
    }

    if (sum < k)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << buttonPresses << endl;
    }
  }

  return 0;
}
