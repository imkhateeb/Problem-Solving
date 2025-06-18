package DSA.GRAPH.Traversals.DFS;

import java.util.*;

public class DFSTraversal {
    private int V;
    private List<List<Integer>> adj;

    public DFSTraversal(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u); // Undirected
    }

    private void dfsUtil(int node, boolean[] visited) {
        visited[node] = true;
        System.out.print(node + " ");

        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    public void DFS() {
        boolean[] visited = new boolean[V];
        System.out.print("DFS Traversal: ");
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        DFSTraversal g = new DFSTraversal(6);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(3, 4); // Disconnected component

        /*
        Dry Run:

        Components: 
        0 - 1 - 2   3 - 4   5

        DFS from 0:
        Output: 0 1 2 3 4 5
        */

        g.DFS();
    }
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
