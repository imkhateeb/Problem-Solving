#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Shortest Path in a Directed Acyclic Graph (DAG)
 * 📌 Problem: Find the shortest path from a source node to all other nodes in a **weighted DAG**.
 * 🔗 Related: Topological Sort, Dynamic Programming on DAGs
 * 
 * 🧠 Intuition:
 * - DAGs don't have cycles → can process nodes in topological order.
 * - Once in topological order, relax edges for each node in order.
 * 
 * ✅ Approach:
 * 1. Perform topological sort using DFS.
 * 2. Initialize `dist[src] = 0` and others as `INT_MAX`.
 * 3. Process nodes in topological order and relax neighbors.
 * 4. Replace `INT_MAX` with `-1` for unreachable nodes.
 * 
 * 🔁 Dry Run:
 * Graph (Adjacency List):
 * 0: (1,2), (4,1)
 * 1: (2,3)
 * 2: (3,6)
 * 4: (2,2), (5,4)
 * 5: (3,1)
 * Source: 0
 * Output: [0,2,3,6,1,5]
 * 
 * ⏱ Time Complexity: O(V + E)
 * 🧠 Space Complexity: O(V + E) for graph and auxiliary arrays
 */

class Solution {
private:
    // Topological sort using DFS
    bool dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& onStack, stack<int>& st) {
        vis[node] = 1;
        onStack[node] = 1;

        for (auto [nbr, wt] : adj[node]) {
            if (!vis[nbr]) {
                if (!dfs(nbr, adj, vis, onStack, st)) return false;
            } else if (onStack[nbr]) {
                return false;  // cycle detected
            }
        }

        onStack[node] = 0;
        st.push(node);  // push after all neighbors are processed (post-order)
        return true;
    }

public:
    vector<int> shortestPathDAG(vector<vector<pair<int, int>>>& adj, int src) {
        int n = adj.size();
        stack<int> st;
        vector<int> vis(n, 0), onStack(n, 0);

        // Run DFS to get topological ordering
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, onStack, st)) {
                    cout << "Cycle detected! Not a DAG.\n";
                    return {};  // Not valid for DAG shortest path
                }
            }
        }

        // Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax edges in topological order
        while (!st.empty()) {
            int node = st.top(); st.pop();

            if (dist[node] != INT_MAX) {
                for (auto [nbr, wt] : adj[node]) {
                    if (dist[node] + wt < dist[nbr]) {
                        dist[nbr] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable values with -1
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};

int main() {
    // Example DAG with 6 nodes (0 to 5)
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int src = 0;

    Solution sol;
    vector<int> result = sol.shortestPathDAG(adj, src);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << '\n';
    }

    return 0;
}
