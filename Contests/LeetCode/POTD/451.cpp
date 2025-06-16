#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

/*
TESTCASES

Input
3
tree
cccaaa
Aabb

Output
eert
aaaccc
bbAa

*/

string frequencySort(string s)
{

  int hash[256] = {0};
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    hash[s[i]]++;
  }

  vector<pair<char, int>> pairs;

  for (int i = 0; i < 256; i++)
  {
    if (hash[i] != 0)
    {
      pairs.push_back({(char)i, hash[i]});
    }
  }

  sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
       { return a.second > b.second; });

  string str = "";
  for (auto &pair : pairs)
  {
    int x = pair.second;
    int y = pair.first;
    for (int i = 0; i < x; i++)
    {
      str.push_back(y);
    }
  }

  return str;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << frequencySort(s) << endl;
  }
  return 0;
}
