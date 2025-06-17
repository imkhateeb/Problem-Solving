package DSA.GRAPH.Traversals.BFS;

import java.util.*;

public class BFSTraversal {
    private int V;
    private List<List<Integer>> adj;

    public BFSTraversal(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    public void BFS() {
        boolean[] visited = new boolean[V];
        System.out.print("BFS Traversal: ");

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                visited[i] = true;

                while (!q.isEmpty()) {
                    int node = q.poll();
                    System.out.print(node + " ");

                    for (int neighbor : adj.get(node)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.add(neighbor);
                        }
                    }
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        BFSTraversal g = new BFSTraversal(6);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(3, 4); // Disconnected component

        /*
        Dry Run:

        Components:
        0 - 1 - 2  3 - 4  5

        BFS Output:
        0 1 2 3 4 5
        */

        g.BFS();
    }
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
