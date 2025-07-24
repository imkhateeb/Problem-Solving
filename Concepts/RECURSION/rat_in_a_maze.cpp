#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int row[4] = {0, 0, 1, -1};
int col[4] = {1, -1, 0, 0};

char dirs[4] = {'R', 'L', 'D', 'U'};

void solve(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &graph, vector<string> &ans, string s, int n)
{

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int ni = i + row[k];
        int nj = j + col[k];
        char dir = dirs[k];

        if (ni >= 0 && ni < n && nj >= 0 && nj < n && graph[ni][nj] == 1)
        {
            if (!vis[ni][nj])
            {
                vis[ni][nj] = 1;
                s.push_back(dir);
                solve(ni, nj, vis, graph, ans, s, n);
                s.pop_back();
                vis[ni][nj] = 0;
            }
        }
    }
}

int main()
{

    int n = 4;
    vector<vector<int>> graph =
        {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}};

    vector<vector<int>> vis(n, vector<int>(n, 0));

    vector<string> ans;

    vis[0][0] = 1;

    solve(0, 0, vis, graph, ans, "", n);

    sort(ans.begin(), ans.end());

    for (auto str : ans)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}