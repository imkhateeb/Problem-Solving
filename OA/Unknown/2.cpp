#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int directions[2][2] = {{1, 0}, {0, 1}};

void bfs(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &ways)
{
  vector<vector<int>> vis(n, vector<int>(n, 0));
  queue<pair<int, int>> q;
  q.push({i, j});
  vis[i][j] = 1;
  ways[i * n + j][i * n + j] = 1;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (auto dir : directions)
    {
      int ni = x + dir[0];
      int nj = y + dir[1];

      if (ni >= 0 && ni < n && nj >= 0 && nj < n)
      {
        ways[i * n + j][ni * n + nj] =
            (ways[i * n + j][ni * n + nj] + ways[i * n + j][x * n + y]) % MOD;

        if (!vis[ni][nj])
        {
          vis[ni][nj] = 1;
          q.push({ni, nj});
        }
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> ways(n * n, vector<int>(n * n, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      bfs(i, j, n, grid, ways);
    }
  }

  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int node = grid[i][j];
      for (int p = 0; p < n; p++)
      {
        for (int q = 0; q < n; q++)
        {
          if (grid[p][q] == node && (p != i || q != j))
          {
            ans = (ans + ways[i * n + j][p * n + q]) % MOD;
          }
        }
      }
    }
  }

  long long final = (n * n) + ans;
  cout << final << endl;

  return 0;
}
