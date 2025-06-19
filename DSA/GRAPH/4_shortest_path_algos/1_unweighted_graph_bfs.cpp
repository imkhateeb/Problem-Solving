#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Shortest Path in Unweighted Graph using BFS
 * 📌 Problem: Find the shortest distance from a source node to all other nodes in an unweighted graph.
 * 🔗 Related: Similar to a single-source shortest path where edge weights = 1
 * 
 * 🧠 Intuition:
 * - In unweighted graphs, all edges have the same cost → use BFS for level-order traversal.
 * - First time a node is visited gives the shortest distance from source.
 * 
 * ✅ Approach:
 * 1. Initialize distance vector with `INT_MAX` (∞), set `dist[src] = 0`.
 * 2. Use a BFS queue that stores pairs `{node, distance}`.
 * 3. Traverse neighbors. If `dist[nbr] > current + 1`, update and enqueue.
 * 4. After BFS, mark unreachable nodes (still `INT_MAX`) as `-1`.
 * 
 * 🔁 Dry Run:
 * Graph (Adjacency List):
 * 0: 1 2
 * 1: 0 3
 * 2: 0 3
 * 3: 1 2
 * Source: 0
 * Output: [0, 1, 1, 2]
 * 
 * ⏱ Time Complexity: O(V + E)
 * 🧠 Space Complexity: O(V) for distance array and BFS queue
 */

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();                  // Total number of nodes
        vector<int> dist(n, INT_MAX);        // Distance from src to each node
        queue<pair<int, int>> q;             // Queue for BFS: {node, distance}

        dist[src] = 0;                       // Distance to source is 0
        q.push({src, 0});

        while (!q.empty()) {
            auto [node, d] = q.front(); q.pop();

            for (int neighbor : adj[node]) {
                // Visit neighbor if not visited with shorter distance yet
                if (dist[neighbor] > d + 1) {
                    dist[neighbor] = d + 1;
                    q.push({neighbor, d + 1});
                }
            }
        }

        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};

int main() {
    // Example graph: 4 nodes (0 to 3)
    vector<vector<int>> adj(4);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2};

    int src = 0;

    Solution sol;
    vector<int> result = sol.shortestPath(adj, src);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << '\n';
    }

    return 0;
}
