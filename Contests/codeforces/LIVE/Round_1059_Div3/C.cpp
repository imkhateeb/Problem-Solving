#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<let>
#define vvi vector<vector<let>>
#define vs vector<string>
#define vpii vector<pair<let, let>>
using namespace std;

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    int a, b;
    cin >> a >> b;
    vector<int> result;
    bool flag = true;

    for (int i = 0; i < 31; i++)
    {
      if (a == b)
        break;

      int b_a = ((1 << i) & a);
      int b_b = ((1 << i) & b);

      if (b_a == b_b)
        continue;

      int zor = (1 << i);

      if (zor > a)
      {
        flag = false;
        break;
      }

      result.push_back(zor);
      a = a ^ zor;
    }

    if (!flag)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << result.size() << endl;
      for (auto it : result)
        cout << it << " ";
      cout << endl;
    }
  }

  return 0;
}
