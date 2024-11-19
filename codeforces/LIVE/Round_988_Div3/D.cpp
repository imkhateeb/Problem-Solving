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
    let n, m, L;
    cin >> n >> m >> L;

    vpii a(n), b(m);
    for (let i = 0; i < n; i++)
      cin >> a[i].ff >> a[i].ss;
    for (let i = 0; i < m; i++)
      cin >> b[i].ff >> b[i].ss;

    priority_queue<int> maxHeap;
    let power = 0, hurdle = 0, jump = 1, step = 0;
    bool flag = false;

    while (hurdle < n)
    {
      let curHurdle = a[hurdle].ff;
      while (power < m && b[power].ff <= curHurdle)
      {
        maxHeap.push(b[power].ss);
        power++;
      }

      let h = a[hurdle].ss - curHurdle + 2;
      while (!maxHeap.empty() && jump < h)
      {
        jump += maxHeap.top();
        maxHeap.pop();
        step++;
      }

      if (jump < h)
      {
        cout << -1 << endl;
        flag = true;
        break;
      }
      hurdle++;
    }

    if (!flag)
      cout << step << endl;
  }

  return 0;
}
