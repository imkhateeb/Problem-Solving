#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fillVector(int n, vector<int> &v)
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
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    fillVector(n, v);
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      if (v[i] >= k)
      {
        int num = (v[i] / k);
        int ans = (v[i] - (num * k));
        if (min > ans)
        {
          min = ans;
        }
      }
    }
    if ( min == INT_MAX ){
      cout << -1 << endl;
    } else {

    cout << min << endl;
    }
  }
  return 0;
}