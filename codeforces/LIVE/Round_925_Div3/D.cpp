#include <bits/stdc++.h>
using namespace std;

void fVec(vector<int> &v, int n)
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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> v;
    fVec(v, n);

    map<string, int> m;
    map<string, int> mp;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
      int rem1 = v[i] % x;
      int rem2 = v[i] % y;

      int a;
      int b;

      if (rem1 == 0)
      {
        a = 0;
      }
      else
      {
        a = x - rem1;
      }


      string temp = to_string(a) + to_string(rem2);
      count += m[temp];

      string hash = to_string(rem1) + to_string(rem2);
      mp[hash] = v[i];
      m[hash]++;
    }

    cout << count << endl;
  }

  return 0;
}