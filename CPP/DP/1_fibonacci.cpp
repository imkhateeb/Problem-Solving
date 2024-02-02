#include <bits/stdc++.h>

using namespace std;


// Recursion + Memoization (Top Down) approach
// Space Complexity: O(n) + O(n) = O(n)
// Time Complexity: O(n)
int fib_m1(int n, vector <int> &dp){

  if ( n == 0 || n == 1 ){
    return n;
  }

  if ( dp[n] != -1 ){
    return dp[n];
  }

  dp[n] = fib_m1(n-1, dp) + fib_m1(n-2, dp);

  return dp[n];
};


// Tabulation (Bottom Up) approach
// Space Complexity: O(n)
// Time Complexity: O(n)
int fib_m2(int n, vector <int> & dp){

  dp[0] = 0;
  dp[1] = 1;

  for ( int i = 2; i <= n; i++ ){
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}


// Space optimized
// Space Complexity: O(1)
// Time Complexity: O(n)
int fib_m3(int n){

  int first = 0;
  int second = 1;
  int curr = 0;

  if ( n == 0 ){
    return first;
  }

  for ( int i = 2; i <= n; i++ ){
    curr = first + second;
    first = second;
    second = curr;
  }

  return curr;
}

int main()
{
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;

  vector <int> dp(n+1, -1);
  int ans1 = fib_m1(n, dp);
  int ans2 = fib_m2(n, dp);
  int ans3 = fib_m3(n);

  
  cout << "The nth fibonacci number is(M-1): " << ans1 << endl;
  cout << "The nth fibonacci number is(M-2): " << ans2 << endl;
  cout << "The nth fibonacci number is(M-3): " << ans3 << endl;

  return 0;
}