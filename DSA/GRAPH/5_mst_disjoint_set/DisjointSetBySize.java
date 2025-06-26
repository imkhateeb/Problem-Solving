/**
 * ✅ Disjoint Set (Union-Find) using Union by Size
 * 📌 Problem: Efficiently manage a collection of disjoint sets with operations:
 *    - `find(u)`: Get representative (root) of set containing `u`
 *    - `union(u, v)`: Merge sets containing `u` and `v` using size heuristic
 * 🔗 Related: Kruskal’s MST, Dynamic Connectivity, Connected Components
 * 
 * 🧠 Intuition:
 * - `parent[]` stores the parent of each node.
 * - `size[]` stores size of each tree (number of nodes in that component).
 * - In `union()`, always attach smaller component to larger one to keep trees shallow.
 * - `find()` uses **path compression** for near-constant time performance.
 * 
 * ✅ Approach:
 * 1. Initialize: `parent[i] = i`, `size[i] = 1` for all nodes.
 * 2. `find(u)` flattens the tree using path compression.
 * 3. `union(u, v)` attaches smaller set under larger one.
 * 
 * ⏱ Time Complexity: O(α(N)) per operation
 * 🧠 Space Complexity: O(N)
 */

class DisjointSet {
    private int[] parent;
    private int[] size;

    public DisjointSet(int n) {
        parent = new int[n];
        size = new int[n];

        // Step 1: Initialize parent and size
        for (int i = 0; i < n; i++) {
            parent[i] = i;    // each node is its own parent initially
            size[i] = 1;      // size of each set is 1 initially
        }
    }

    // Step 2: Find with path compression
    public int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // path compression
        }
        return parent[u];
    }

    // Step 3: Union by size
    public void union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return;  // Already in the same set

        // Always attach smaller set to larger one
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }

    // Utility: Check if two nodes are in the same component
    public boolean isConnected(int u, int v) {
        return find(u) == find(v);
    }
}

public class DisjointSetBySize {
    public static void main(String[] args) {
        int n = 7; // Nodes from 0 to 6
        DisjointSet ds = new DisjointSet(n);

        // Sample unions
        ds.union(0, 1);
        ds.union(2, 3);
        ds.union(1, 2);  // Connect 0-1-2-3
        ds.union(4, 5);

        // Check connectivity
        System.out.println("Are 0 and 3 connected? " + ds.isConnected(0, 3)); // true
        System.out.println("Are 0 and 4 connected? " + ds.isConnected(0, 4)); // false

        ds.union(3, 4); // Merge both sets

        System.out.println("Are 1 and 5 connected now? " + ds.isConnected(1, 5)); // true
    }
}
