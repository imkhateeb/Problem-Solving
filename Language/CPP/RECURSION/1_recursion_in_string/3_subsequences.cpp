#include <bits/stdc++.h>
using namespace std;

void subSequences(
    string s,
    string output,
    int index,
    vector<string> &ans)
{
  if (index == s.size())
  {
    ans.push_back(output);
    return;
  }

  // Exclude
  subSequences(s, output, index + 1, ans);

  // Include
  output += s[index];
  subSequences(s, output, index + 1, ans);
}

int main()
{
  string s;
  cout << "Enter the string: ";
  cin >> s;

  int n = s.size();

  vector<string> ans;
  string output;
  subSequences(s, output, 0, ans);

  int p = ans.size();
  cout << "Subsequence is: ";
  cout << "{";
  for (int i = 0; i < p; i++)
  {
    if (i == 0)
    {
      cout << "{}, ";
    }
    else
    {

      if (i == p - 1) // last element
        cout << ans[i];
      else // not last element
        cout << ans[i] << ", ";
    }
  }
  cout << "}";

  return 0;
}