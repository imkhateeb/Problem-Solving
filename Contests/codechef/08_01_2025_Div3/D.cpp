#include <bits/stdc++.h>
#define let long long
using namespace std;

vector<pair<int, int>> unionOfSegments(vector<pair<int, int>> &segments)
{
  vector<pair<int, int>> result;

  if (segments.empty())
    return result;

  sort(segments.begin(), segments.end());

  int st = segments[0].first, en = segments[0].second;

  for (int i = 1; i < segments.size(); i++)
  {
    if (segments[i].first <= en)
    {
      en = max(en, segments[i].second);
    }
    else
    {
      result.push_back({st, en});
      st = segments[i].first;
      en = segments[i].second;
    }
  }

  result.push_back({st, en});
  return result;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, pair<int, int>> pos;

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (pos.find(a[i]) == pos.end())
      {
        pos[a[i]] = {i, i};
      }
      else
      {
        pos[a[i]].second = i;
      }
    }

    vector<pair<int, int>> segments;
    for (auto &[key, range] : pos)
    {
      if (range.first != range.second)
      {
        segments.push_back(range);
      }
    }

    vector<pair<int, int>> segUnion = unionOfSegments(segments);

    let ans = 0;
    for (auto &pair : segUnion)
    {
      unordered_set<int> temp(a.begin() + pair.first, a.begin() + pair.second + 1);
      ans += temp.size();
    }

    cout << ans << endl;
  }

  return 0;
}
