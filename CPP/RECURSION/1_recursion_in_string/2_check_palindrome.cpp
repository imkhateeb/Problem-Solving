#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(string s, int i, int j ){
  // Base case
  if ( i >= j ) return true;

  // Recursive intuition
  if ( s[i] != s[j] ) return false;

  // Recursive call
  check_palindrome(s, i+1, j-1);
}
int main()
{
  string s = "binod";

  bool is_palindrome = check_palindrome(s, 0, s.length() - 1);

  if (is_palindrome)
    cout << "Yes, it is a palindrome\n";
  else
    cout << "No, it is not a palindrome\n";
  return 0;
}