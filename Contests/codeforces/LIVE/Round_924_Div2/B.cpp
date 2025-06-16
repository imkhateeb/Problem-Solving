#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vpii vector<pair<int, int>>

using namespace std;

void fVec(vector<long long> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<long long> v;
    fVec(v, n);

    sort(all(v));
    int maxC = 1;
    int same = 0;

    int st = 0;

    for (int i = 1; i < n; i++)
    {
      if ((v[i] - v[st]) < n)
      {
        if (v[i] == v[i - 1])
        {
          same++;
        }
      }
      else
      {
        maxC = max(maxC, i - st - same);
        while (st < n && (v[i] - v[st] >= n))
        {
          if ((st < n - 1) && (v[st] == v[st + 1]))
          {
            same--;
          }
          st++;
        }
      }

      if (i == n - 1)
      {
        if ((v[i] - v[st]) < n)
        {
          maxC = max(maxC, i - st - same + 1);
        }
      }
    }
    cout << maxC << endl;
  }

  return 0;
}
