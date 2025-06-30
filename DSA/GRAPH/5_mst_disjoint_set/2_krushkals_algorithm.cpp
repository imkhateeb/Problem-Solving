#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Kruskal's Algorithm using Disjoint Set (Union by Size)
 * 📌 Problem: Find the **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph.
 * 🔗 Related: Greedy Algorithm, Disjoint Set Union (DSU), Union by Size
 * 
 * 🧠 Intuition:
 * - Greedily add the smallest edge that doesn't form a cycle.
 * - Use DSU to track which components are connected.
 * 
 * ✅ Approach:
 * 1. Sort all edges by weight.
 * 2. Initialize DSU structure.
 * 3. For each edge (u-v):
 *    - If u and v are in different components, include edge in MST.
 *    - Merge components using Union by Size.
 * 4. Stop when `V - 1` edges are included (for V nodes).
 * 
 * ⏱ Time Complexity: O(E log E) for sorting + O(E * α(V)) for union-find
 * 🧠 Space Complexity: O(V)
 */

// Disjoint Set Union with Union by Size + Path Compression
class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    // Step 1: Initialize parent and size arrays
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Step 2: Find with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Step 3: Union by size
    void unionBySize(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return;

        // Attach smaller tree under larger tree
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }

    // Utility: check if two nodes are in same component
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

// Kruskal's Algorithm implementation
class Solution {
public:
    int kruskalsAlgo(vector<pair<int, pair<int, int>>> &edges, int V) {
        int ans = 0;          // Total weight of MST
        DisjointSet ds(V);    // DSU for V vertices

        // Step 1: Sort edges by weight
        sort(edges.begin(), edges.end());

        int noOfEdges = 0;

        // Step 2: Iterate over edges
        for (auto edge : edges) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            // Step 3: If u and v are already connected, skip
            if (ds.isConnected(u, v)) continue;

            // Step 4: Otherwise, include edge in MST
            ds.unionBySize(u, v);
            ans += wt;
            noOfEdges++;

            // Early stop: MST complete when V - 1 edges included
            if (noOfEdges == V - 1) return ans;
        }

        return ans; // Return total weight of MST
    }
};

int main() {
    int V = 4;
    vector<pair<int, pair<int, int>>> edges = {
        {10, {0, 1}},
        {15, {1, 2}},
        {5, {0, 2}},
        {20, {1, 3}},
        {30, {2, 3}}
    };

    Solution sol;
    int mstWeight = sol.kruskalsAlgo(edges, V);

    cout << "Minimum Spanning Tree weight: " << mstWeight << endl;
    return 0;
}
