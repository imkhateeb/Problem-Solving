
/**
 * ✅ Disjoint Set (Union-Find) using Union by Rank
 * 📌 Problem: Efficiently manage a collection of disjoint sets, with support for:
 *    - `find(u)`: Find the representative (root) of set containing `u`
 *    - `union(u, v)`: Merge sets containing `u` and `v`
 * 🔗 Related: Kruskal's Algorithm, Connected Components, Dynamic Connectivity
 * 
 * 🧠 Intuition:
 * - `parent[]` tracks each node's parent.
 * - `rank[]` keeps tree height (or size); always attach smaller tree to larger.
 * - `find()` uses path compression for flattening trees.
 * 
 * ✅ Approach:
 * 1. Initialize `parent[i] = i` and `rank[i] = 0` for all nodes.
 * 2. `find(u)` uses recursion with path compression.
 * 3. `union(u, v)` compares rank of root(u) and root(v) to merge.
 * 
 * ⏱ Time Complexity: O(α(N)) per operation (very close to constant)
 * 🧠 Space Complexity: O(N)
 */

class DisjointSet {
    private int[] parent;
    private int[] rank;

    public DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];

        // Step 1: Initialize each node to be its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;  // All trees start with rank 0
        }
    }

    // Step 2: Find with path compression
    public int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // Path compression
        }
        return parent[u];
    }

    // Step 3: Union by rank
    public void union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return;  // Already in same set

        // Attach smaller rank tree under larger rank tree
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    // Utility method to check if two nodes are connected
    public boolean isConnected(int u, int v) {
        return find(u) == find(v);
    }
}

public class DisjointSetByRank {
    public static void main(String[] args) {
        int n = 7;  // Nodes 0 to 6
        DisjointSet ds = new DisjointSet(n);

        // Sample unions
        ds.union(0, 1);
        ds.union(1, 2);
        ds.union(3, 4);
        ds.union(5, 6);
        ds.union(4, 5);

        // Check if nodes are connected
        System.out.println("Are 0 and 2 connected? " + ds.isConnected(0, 2)); // true
        System.out.println("Are 0 and 3 connected? " + ds.isConnected(0, 3)); // false

        ds.union(2, 3); // connect components

        System.out.println("Are 0 and 4 connected now? " + ds.isConnected(0, 4)); // true
    }
}
