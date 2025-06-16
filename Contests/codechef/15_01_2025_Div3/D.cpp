#include <bits/stdc++.h>
#define let long long
using namespace std;

let minSubarraySum(vector<let> &arr, let x)
{
  let windowSum = 0;
  for (let i = 0; i < x; i++)
  {
    windowSum += arr[i];
  }

  let minSum = windowSum;

  for (let i = x; i < arr.size(); i++)
  {
    windowSum += arr[i] - arr[i - x]; // Slide the window by subtracting the element that left and adding the new one
    minSum = min(minSum, windowSum);  // Update the minimum sum
  }

  return minSum;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let N;
    cin >> N;
    vector<let> A;
    vector<let> B;

    for (int i = 0; i < N; i++)
    {
      let X;
      cin >> X;
      if (X >= 0)
      {
        A.push_back(X);
      }
      else
      {
        B.push_back(X);
      }
    }

    let maxi = A.size() == 0 ? 0 : *max_element(A.begin(), A.end());

    let sum = minSubarraySum(A, A.size() - B.size());

    for (int i = 0; i < N; i++)
    {
      sum += A[i];
    }

    if (maxi <= 0)
    {
      cout << 0 << endl;
    }
    else if (sum > maxi)
    {
      cout << sum << endl;
    }
    else
    {
      cout << maxi << endl;
    }
  }
  return 0;
}
