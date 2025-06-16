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

class DisjointSet
{
  vector<int> size, parent;

public:
  DisjointSet(int n)
  {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findParent(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }

  void unionBySize(int u, int v)
  {
    int ulpu = findParent(u);
    int ulpv = findParent(v);

    if (ulpu == ulpv)
      return;

    if (size[ulpv] > size[ulpu])
    {
      parent[ulpu] = ulpv;
      size[ulpv] += size[ulpu];
    }
    else
    {
      parent[ulpv] = ulpu;
      size[ulpu] += size[ulpv];
    }
  }
};

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n, m1, m2;
    cin >> n >> m1 >> m2;

    DisjointSet ds1(n);
    DisjointSet ds2(n);

    let ans = 0;

    vector<pair<int, int>> vp1;
    vector<pair<int, int>> vp2;

    for (let i = 0; i < m1; i++)
    {
      let u, v;
      cin >> u >> v;
      vp1.push_back({u, v});
    }

    for (let i = 0; i < m2; i++)
    {
      let u, v;
      cin >> u >> v;
      vp2.push_back({u, v});
      ds2.unionBySize(u, v);
    }

    for (let i = 0; i < m1; i++)
    {
      let u = vp1[i].first;
      let v = vp1[i].second;

      if (ds2.findParent(u) != ds2.findParent(v))
      {
        ans++;
      }
      else
      {
        ds1.unionBySize(u, v);
      }
    }

    for (let i = 0; i < m2; i++)
    {
      let u = vp2[i].first;
      let v = vp2[i].second;

      if (ds1.findParent(u) != ds1.findParent(v))
      {
        ans++;
        ds1.unionBySize(u, v);
      }
    }

    cout << ans << endl;
  }

  return 0;
}
