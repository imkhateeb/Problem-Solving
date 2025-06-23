#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    int prims(vector<vector<pair<int, int>>> &adj)
    {

        int n = adj.size();
        vector<int> vis(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, 0});

        int ans = 0;

        while(!q.empty()){
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();

            if(vis[node] == 1) continue;

            vis[node] = 1;
            ans += wt;


            for(auto pr: adj[node]){
                if(!vis[pr.first]){
                    q.push({pr.second, pr.first});
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    // vector<vector<pair<int, int>>> graph = { {{1, 2}, {3, 6}}, {{4, 5}, {2, 3}, {3, 8}}, {}, {}, {{2, 7}}};
    vector<vector<pair<int, int>>> graph = { {{1, 2}, {2, 1}}, {{2, 1}}, {{3, 2}}, {{4, 1}}, {{2, 2}}};

    cout << "MST: " << sol.prims(graph) << endl;

    return 0;
}