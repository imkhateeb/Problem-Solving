#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Dijkstra’s Algorithm using Set (Balanced BST)
 * 📌 Problem: Find the shortest path from a source node to all other nodes in a **weighted graph** (no negative weights).
 * 🔗 Related: Greedy, STL Set, BFS-like traversal with ordered structure
 * 
 * 🧠 Intuition:
 * - Similar to priority queue, but `set` gives more control:
 *   - Allows deleting a specific (dist, node) pair.
 *   - Ensures only the most up-to-date (dist, node) remains.
 * 
 * ✅ Approach:
 * 1. Initialize distances: `dist[src] = 0`, others as `INT_MAX`.
 * 2. Use a set of pairs `(distance, node)` to process nodes.
 * 3. Always process node with smallest distance.
 * 4. On relaxing neighbors:
 *     - If a better distance is found, remove old `(dist[nbr], nbr)` from set (if exists), insert new.
 * 5. Replace `INT_MAX` with `-1` for unreachable nodes.
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
 * ⏱ Time Complexity: O((V + E) log V)
 * 🧠 Space Complexity: O(V + E) for graph and auxiliary arrays
 */

class Solution {
public:
    vector<int> dijkstraSet(int n, vector<vector<pair<int, int>>>& adj, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Set of pairs: (distance, node), sorted by distance
        set<pair<int, int>> st;
        st.insert({0, src});

        while (!st.empty()) {
            auto [d, node] = *st.begin();
            st.erase(st.begin());

            for (auto [nbr, wt] : adj[node]) {
                if (dist[node] + wt < dist[nbr]) {
                    // Remove old record if exists
                    if (dist[nbr] != INT_MAX) {
                        st.erase({dist[nbr], nbr});
                    }

                    dist[nbr] = dist[node] + wt;
                    st.insert({dist[nbr], nbr});
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
    // Example weighted graph with 6 nodes (0 to 5)
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
    vector<int> result = sol.dijkstraSet(n, adj, src);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << '\n';
    }

    return 0;
}
