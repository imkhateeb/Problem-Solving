#include <bits/stdc++.h>

/**
 * ✅ Leetcode 785: Is Graph Bipartite?
 * 🔗 https://leetcode.com/problems/is-graph-bipartite/
 * 
 * 📌 Problem Statement:
 * - Check whether a given graph (can be disconnected) is bipartite.
 * - A graph is bipartite if its vertices can be divided into 2 sets such that no two adjacent vertices share the same set.
 * 
 * 🧠 Intuition:
 * - If we can color the graph using two colors such that no adjacent nodes have the same color, it's bipartite.
 * - DFS/BFS traversal helps ensure alternate coloring.
 * 
 * ✅ Approach:
 * 1. Traverse all connected components.
 * 2. For each unvisited node, start DFS and try to color it using either `1` or `-1`.
 * 3. If a neighbor is already colored with the same color → not bipartite.
 * 
 * 🔁 Dry Run:
 * Example: 
 *      0 -- 1
 *      |    |
 *      3 -- 2
 * - Start at 0 → color = 1
 * - Visit 1 → color = -1
 * - Visit 2 → color = 1
 * - Visit 3 → color = -1
 * - Back to 0 → color matches → valid
 * → Bipartite!
 * 
 * ⏱ Time Complexity: O(V + E) 
 * 🧠 Space Complexity: O(V) for visited/color array + call stack
 * 
 * 🔗 Similar Problems:
 * - Leetcode 886. Possible Bipartition
 * - Graph Coloring Problems (2-colorable check)
 */

class Solution {
private:
    // DFS function to try coloring the graph using 1 and -1
    bool dfs(vector<vector<int>>& graph, int node, int color, vector<int>& vis) {
        vis[node] = color;

        for (auto nbr : graph[node]) {
            if (!vis[nbr]) {
                // Color neighbor with opposite color
                if (!dfs(graph, nbr, -color, vis)) {
                    return false; // Conflict detected
                }
            } else if (vis[nbr] == color) {
                // Same color as current node → not bipartite
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0); // 0 = unvisited, 1 and -1 are colors

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // Start DFS from unvisited node
                if (!dfs(graph, i, 1, vis)) {
                    return false; // Found non-bipartite component
                }
            }
        }

        return true; // All components are bipartite
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    
    cout << "Is graph bipartite? " << (sol.isBipartite(graph) ? "Yes" : "No") << endl;

    return 0;
}
