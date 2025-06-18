#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Topological Sort using Kahn's Algorithm (BFS)
 * 📌 Only works for Directed Acyclic Graphs (DAGs)
 * 🔗 Related: https://leetcode.com/problems/course-schedule-ii/
 * 
 * 🧠 Intuition:
 * - Count in-degrees of all nodes.
 * - Start with nodes having in-degree 0.
 * - Remove nodes level by level while updating neighbors.
 * - If all nodes are visited → valid topological order.
 * 
 * ✅ Approach:
 * 1. Compute in-degree for each node.
 * 2. Use a queue to store nodes with in-degree 0.
 * 3. BFS-like processing and form the result.
 * 4. If cycle exists → result.size() < V
 * 
 * 🔁 Dry Run:
 * Graph:
 *      5 → 2
 *      5 → 0
 *      4 → 0
 *      4 → 1
 *      2 → 3
 *      3 → 1
 * Output: 4 5 2 0 3 1 (one valid order)
 * 
 * ⏱ Time Complexity: O(V + E)
 * 🧠 Space Complexity: O(V) for queue, in-degree, result
 */

class Solution {
public:
    vector<int> topoSortKahn(int V, vector<vector<int>>& graph) {
        vector<int> inDegree(V, 0);
        vector<int> result;

        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);

            for (int nbr : graph[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if (result.size() != V) {
            return {}; // Cycle detected
        }

        return result;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> graph(V);
    graph[5] = {0, 2};
    graph[4] = {0, 1};
    graph[2] = {3};
    graph[3] = {1};

    Solution sol;
    vector<int> topo = sol.topoSortKahn(V, graph);

    if (topo.empty()) {
        cout << "Cycle detected. Topological sort not possible.\n";
    } else {
        cout << "Topological Sort (Kahn’s): ";
        for (int node : topo) cout << node << " ";
        cout << endl;
    }

    return 0;
}
