#include <bits/stdc++.h>
using namespace std;

/*
You are given an array A of integers of size N. You will be given Q quweies. Each query will have two integers L and R. You have to find the GCD of all the elements by removing the subarray from L to R (both inclusive).

Constraints
2 <= T, N <= 10^5
1 <= Q <= 10^5
1 <= A[i] <= 10^9
1 <= L, R <= N
L <= R

Note: Sum of N over all test cases will not exceed 10^6
*/

const int N = 100010;
int arr[N];
long long forward_gcd[N];
long long backward_gcd[N];

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> arr[i];
    }

    forward_gcd[0] = backward_gcd[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
      forward_gcd[i] = __gcd(forward_gcd[i - 1], arr[i]);
    }
    for (int i = n; i >= 1; i--)
    {
      backward_gcd[i] = __gcd(backward_gcd[i + 1], arr[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
      int l, r;
      cin >> l >> r;
      cout << __gcd(forward_gcd[l - 1], backward_gcd[r + 1]) << endl;
    }
  }

  return 0;
}