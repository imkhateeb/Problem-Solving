#include <bits/stdc++.h>

/**
 * ✅ Cycle Detection in Undirected Graph using BFS
 *
 * 🧠 Intuition:
 * - In an undirected graph, a cycle exists if we revisit a node from a neighbor that is not its parent.
 * - BFS is used to traverse level-by-level and track parent for each node.
 *
 * 📌 How It Works:
 * - Use a queue to perform BFS from each unvisited node.
 * - Maintain parent for each node during traversal.
 * - If a visited neighbor is NOT the parent → cycle exists.
 *
 * 🔁 Dry Run Example:
 *      0 - 1 - 2
 *          \  |
 *            3
 * → BFS from 0: visit 1 (parent 0), visit 2 (parent 1), then 3 (parent 2), then again visit 1 → cycle!
 *
 * ⏱ Time Complexity: O(V + E)
 * 🧠 Space Complexity: O(V)
 *
 * 🔗 Similar Problems:
 * - Leetcode 261. Graph Valid Tree (detect cycle)
 */

bool isCycleBFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);

    for (int start = 0; start < V; ++start) {
        if (!vis[start]) {
            queue<pair<int, int>> q; // {node, parent}
            q.push({start, -1});
            vis[start] = 1;

            while (!q.empty()) {
                auto [node, parent] = q.front(); q.pop();

                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push({neighbor, node});
                    } else if (neighbor != parent) {
                        // 🔁 Back edge found, cycle detected
                        return true;
                    }
                }
            }
        }
    }

    return false; // No cycle found
}
