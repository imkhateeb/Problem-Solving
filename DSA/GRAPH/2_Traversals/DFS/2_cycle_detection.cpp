#include <bits/stdc++.h>

/**
 * ✅ Cycle Detection in Undirected Graph using DFS
 *
 * 🧠 Intuition:
 * - DFS goes deep into each branch. If we visit a visited node that’s NOT the parent → cycle!
 *
 * 📌 How It Works:
 * - Start DFS from each unvisited node.
 * - Keep track of parent while recursing.
 * - If a neighbor is visited and not parent → cycle detected.
 *
 * 🔁 Dry Run Example:
 *      0 - 1 - 2
 *          \  |
 *            3
 * → DFS from 0 → 1 → 2 → 3 → revisit 1 (not parent) → cycle!
 *
 * ⏱ Time Complexity: O(V + E)
 * 🧠 Space Complexity: O(V)
 */

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            if (dfs(neighbor, node, adj, vis)) return true;
        } else if (neighbor != parent) {
            // 🔁 Back edge → cycle
            return true;
        }
    }

    return false;
}

bool isCycleDFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) return true;
        }
    }

    return false;
}
