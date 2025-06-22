#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Dijkstra’s Algorithm using Priority Queue
 * 📌 Problem: Find the shortest path from a source node to all other nodes in a **weighted graph** (no negative weights).
 * 🔗 Related: Greedy Algorithm, BFS-like expansion with priority queue
 * 
 * 🧠 Intuition:
 * - Use a min-heap (priority queue) to always expand the next closest node.
 * - Once a node is processed with the shortest distance, we skip reprocessing it.
 * 
 * ✅ Approach:
 * 1. Initialize distance of `src` as 0, others as `INT_MAX`.
 * 2. Push `(0, src)` into a min-heap.
 * 3. While heap not empty:
 *     - Pop the node with smallest distance.
 *     - Relax its neighbors: if shorter path found, update and push to heap.
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
 * ⏱ Time Complexity: O((V + E) log V)
 * 🧠 Space Complexity: O(V + E) for graph and auxiliary arrays
 */

class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();

            // Skip if we have already found a better path
            if (d > dist[node]) continue;

            for (auto [nbr, wt] : adj[node]) {
                if (dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
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
    vector<int> result = sol.dijkstra(n, adj, src);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << '\n';
    }

    return 0;
}
