import java.util.*;

/**
 * ✅ Floyd-Warshall Algorithm
 * 📌 Problem: Find the **shortest path between all pairs** of nodes in a **weighted graph** (can have negative weights but no negative cycles).
 * 🔗 Related: Dynamic Programming, All-Pairs Shortest Path (APSP)
 * 
 * 🧠 Intuition:
 * - Let `dist[i][j]` be the shortest distance from node `i` to node `j`.
 * - Try every node `k` as an intermediate between `i` and `j`.
 * - If `dist[i][k] + dist[k][j] < dist[i][j]`, update it.
 * 
 * ✅ Approach:
 * 1. Initialize a `dist` matrix:
 *    - `dist[i][j] = weight` if edge (i→j) exists
 *    - `dist[i][i] = 0`
 *    - `dist[i][j] = INF` if no direct edge
 * 2. For each intermediate node `k`, update all pairs `(i, j)` using:  
 *    `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
 * 3. (Optional) Detect negative cycles: if `dist[i][i] < 0` for any `i`
 * 
 * 🔁 Dry Run:
 * Nodes: 0 to 3  
 * Edges: 0→1(5), 0→3(10), 1→2(3), 2→3(1)  
 * Result: dist matrix with all-pairs shortest paths
 * 
 * ⏱ Time Complexity: O(V³)
 * 🧠 Space Complexity: O(V²)
 */

class Solution {
    static final int INF = (int)1e9;

    public int[][] floydWarshall(int V, int[][] edges) {
        int[][] dist = new int[V][V];

        // Step 1: Initialize distance matrix
        for (int i = 0; i < V; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            dist[u][v] = wt;  // Directed edge
        }

        // Step 2: Floyd-Warshall Core Loop
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Step 3: Check for negative weight cycles
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                System.out.println("Negative weight cycle detected!");
                return new int[0][0];
            }
        }

        // Replace INF with -1 for unreachable pairs
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) dist[i][j] = -1;
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int V = 4;
        int[][] edges = {
            {0, 1, 5},
            {0, 3, 10},
            {1, 2, 3},
            {2, 3, 1}
        };

        Solution sol = new Solution();
        int[][] result = sol.floydWarshall(V, edges);

        System.out.println("All-pairs shortest distances:");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                System.out.print("[" + i + " → " + j + "]: " + result[i][j] + "  ");
            }
            System.out.println();
        }
    }
}
