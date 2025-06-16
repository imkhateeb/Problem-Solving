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
    let N;
    cin >> N;
    vi A(N);
    for (let i = 0; i < N; i++)
    {
      cin >> A[i];
    }

    // Stack to keep track of merged elements
    vector<let> stack;
    vector<let> result;

    for (let i = 0; i < N; i++)
    {
      let x = A[i];
      while (!stack.empty() && stack.back() == x)
      {
        // Pop the top element and double x
        stack.pop_back();
        x *= 2;
      }
      stack.push_back(x);
      // The size of the stack is the minimum size for the current prefix
      result.pb(stack.size());
    }

    // Print the result for this test case
    for (let i = 0; i < result.size(); i++)
    {
      cout << result[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
