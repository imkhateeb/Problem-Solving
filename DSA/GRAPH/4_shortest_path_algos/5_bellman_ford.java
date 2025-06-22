import java.util.*;

/**
 * ✅ Bellman-Ford Algorithm
 * 📌 Problem: Find the shortest path from a source node to all other nodes in a
 * **weighted graph**, which may have **negative weights**.
 * 🔗 Related: Dynamic Programming, Edge Relaxation
 * 
 * 🧠 Intuition:
 * - For a graph with `V` nodes, the shortest path can have at most `V - 1`
 * edges.
 * - Repeatedly relax all edges `V - 1` times to find shortest paths.
 * - After that, one more pass can detect negative weight cycles.
 * 
 * ✅ Approach:
 * 1. Initialize distances: `dist[src] = 0`, others as `Integer.MAX_VALUE`.
 * 2. For `V - 1` times, relax all edges: if `dist[u] + wt < dist[v]`, update
 * `dist[v]`.
 * 3. (Optional) For negative cycle check, do 1 more pass: if any edge can still
 * be relaxed, report a cycle.
 * 4. Replace `Integer.MAX_VALUE` with `-1` for unreachable nodes.
 * 
 * 🔁 Dry Run:
 * Edges (u, v, wt):
 * 0 → 1 (2), 0 → 4 (1), 1 → 2 (3), 2 → 3 (6), 4 → 2 (2), 4 → 5 (4), 5 → 3 (1)
 * Source: 0
 * Output: [0, 2, 3, 6, 1, 5]
 * 
 * ⏱ Time Complexity: O(V * E)
 * 🧠 Space Complexity: O(V)
 */

class Solution {
    static class Edge {
        int from, to, weight;

        Edge(int f, int t, int w) {
            from = f;
            to = t;
            weight = w;
        }
    }

    public int[] bellmanFord(int V, List<Edge> edges, int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Step - 1: Relax all edges V-1 times
        for (int i = 0; i < V; i++) {
            for (Edge e : edges) {
                if (dist[e.from] != Integer.MAX_VALUE && dist[e.from] + e.weight < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.weight;
                }
            }
        }

        // Step - 2: Check for negative cycles
        for (Edge e : edges) {
            if (dist[e.from] != Integer.MAX_VALUE && dist[e.from] + e.weight < dist[e.to]) {
                System.out.println("Negative weight cycle detected!");
                return new int[0];
            }
        }

        // Step - 3: Make unreachable vertex from src as -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == Integer.MAX_VALUE) {
                dist[i] = -1;
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int V = 6;
        List<Edge> edges = new ArrayList<>();

        // Construct a graph
        edges.add(new Edge(0, 1, 2));
        edges.add(new Edge(0, 4, 1));
        edges.add(new Edge(1, 2, 3));
        edges.add(new Edge(2, 3, 6));
        edges.add(new Edge(4, 2, 2));
        edges.add(new Edge(4, 5, 4));
        edges.add(new Edge(5, 3, 1));

        int src = 0;
        Solution sol = new Solution();

        int[] result = sol.bellmanFord(V, edges, src);

        System.out.println("Shortest distances from source node " + src + ":");
        for (int i = 0; i < result.length; i++) {
            System.out.println("Node " + i + ": " + result[i]);
        }
    }
}