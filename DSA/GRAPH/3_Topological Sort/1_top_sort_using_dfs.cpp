#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Topological Sort using DFS
 * 📌 Only works for Directed Acyclic Graphs (DAGs)
 * 🔗 Related: https://leetcode.com/problems/course-schedule-ii/
 * 
 * 🧠 Intuition:
 * - Perform DFS and push nodes into a stack **after** visiting all their neighbors (post-order).
 * - Reverse the stack to get the topological order.
 * 
 * ✅ Approach:
 * 1. Traverse all unvisited nodes.
 * 2. Use a recursion stack to detect cycles.
 * 3. Push nodes into result stack on returning from DFS.
 * 
 * 🔁 Dry Run:
 * Graph:
 *      5 → 2
 *      5 → 0
 *      4 → 0
 *      4 → 1
 *      2 → 3
 *      3 → 1
 * Output: 5 4 2 3 1 0 (one possible order)
 * 
 * ⏱ Time Complexity: O(V + E)
 * 🧠 Space Complexity: O(V) visited + O(V) stack
 */

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& onStack, stack<int>& st) {
        vis[node] = 1;
        onStack[node] = 1;

        for (auto nbr : graph[node]) {
            if (!vis[nbr]) {
                if (!dfs(nbr, graph, vis, onStack, st)) return false;
            } else if (onStack[nbr]) {
                return false; // Cycle detected
            }
        }

        onStack[node] = 0;
        st.push(node); // Post-order push
        return true;
    }

public:
    vector<int> topoSortDFS(int V, vector<vector<int>>& graph) {
        vector<int> vis(V, 0), onStack(V, 0);
        stack<int> st;
        vector<int> result;

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (!dfs(i, graph, vis, onStack, st)) {
                    return {}; // Cycle → no topological sort
                }
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
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
    vector<int> topo = sol.topoSortDFS(V, graph);

    if (topo.empty()) {
        cout << "Cycle detected. Topological sort not possible.\n";
    } else {
        cout << "Topological Sort (DFS): ";
        for (int node : topo) cout << node << " ";
        cout << endl;
    }

    return 0;
}
