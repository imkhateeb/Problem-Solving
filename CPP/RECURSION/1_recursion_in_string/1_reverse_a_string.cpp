#include <bits/stdc++.h>
using namespace std;

void reverse_string(string &s, int i, int j)
{
  // Base case
  if (i > j)
    return;

  // Recursive intuition
  swap(s[i], s[j]);

  // Recursive call
  reverse_string(s, i + 1, j - 1);
}

int main()
{
  string s = "binod";

  cout << "Original string is: " << s << "\n"; // "binod"

  reverse_string(s, 0, s.length() - 1);

  cout << "Reversed string is: " << s << "\n"; // "donib
  return 0;
}