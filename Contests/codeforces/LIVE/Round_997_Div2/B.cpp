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

void dfs(int node, vector<vector<int>> &adj, unordered_map<int, int> &vis, stack<int> &st)
{

  vis[node] = 1;

  for (auto neighbour : adj[node])
  {
    if (!vis[neighbour])
    {
      dfs(neighbour, adj, vis, st);
    }
  }

  st.push(node);
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    vector<string> v(n);
    for (let i = 0; i < n; i++)
    {
      cin >> v[i];
    }

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {

        if (v[i][j] == '1')
        {

          adj[i].push_back(j);
        }
      }
    }

    unordered_map<int, int> vis;
    stack<int> st;
    for (int i = 0; i < adj.size(); i++)
    {
      if (!vis[i])
      {
        dfs(i, adj, vis, st);
      }
    }

    while (!st.empty())
    {
      cout << st.top() + 1 << " ";
      st.pop();
    }
    cout << endl;
  }

  return 0;
}
