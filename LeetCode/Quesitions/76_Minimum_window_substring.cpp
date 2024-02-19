#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
  int n = s.size();
  int m = t.size();
  if (n < m)
  {
    return "";
  }

  int alphas[256] = {0};
  int alphat[256] = {0};

  for (int i = 0; i < m; i++)
  {
    alphat[t[i]]++;
  }

  for (int i = 0; i < n; i++)
  {
    alphas[s[i]]++;
  }

  if (m == n)
  {
    for (int i = 0; i < 256; i++)
    {
      if (alphas[i] != alphat[i])
      {
        return "";
      }
    }
    return s;
  }

  for (int i = 0; i < 256; i++)
  {
    alphas[i] = 0;
  }

  int start = 0;
  int count = m;
  int end = n - 1;

  for (int i = 0; i < n; i++)
  {
    // cout << "i: " << i << endl;
    if ((alphas[s[i]] < alphat[s[i]]) && (alphat[s[i]] != 0))
    {
      count--;
      alphas[s[i]]++;
    }
    else if (alphat[s[i]] != 0)
    {
      alphas[s[i]]++;
    }

    if (count == m)
    {
      start = i + 1;
    }
    else if (count == 0)
    {
      count = -1;
      end = i;
    }
    // cout << "start: " << start << " end: " << end << " count: " << count << endl;

    if ((count == 0) && (alphas[s[i]] > alphat[s[i]]))
    {
      int p = start;
      vector<int> temp;
      while (alphas[s[p]] >= alphat[s[p]])
      {
        if (alphas[s[p]] > alphat[s[p]])
        {
          temp.push_back(p);
        }
        else if ((alphas[s[p]] == alphat[s[p]]) && (alphat[s[p]] != 0))
        {
          int x = temp.size();
          for (int j = 0; j < x; j++)
          {
            alphas[s[temp[j]]]--;
          }
          start = p;
          end = i;
          break;
        }
        p++;
      }
    }
  }

  string ans = "";
  for (int i = start; i <= end; i++)
  {
    ans.push_back(s[i]);
  }

  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    string s, t;
    cin >> s >> t;
    cout << "String is: " << minWindow(s, t) << endl;
  }
  return 0;
}