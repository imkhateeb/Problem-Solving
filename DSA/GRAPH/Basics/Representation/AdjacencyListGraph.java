import java.util.*;

public class AdjacencyListGraph {
    private int V;
    private boolean isDirected;
    private List<List<Integer>> adj;

    public AdjacencyListGraph(int V, boolean isDirected) {
        this.V = V;
        this.isDirected = isDirected;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        if (!isDirected)
            adj.get(v).add(u);
    }

    public void printGraph() {
        System.out.println("Adjacency List:");
        for (int i = 0; i < V; i++) {
            System.out.print(i + ": ");
            for (int neighbor : adj.get(i)) {
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Is the graph directed? (true/false): ");
        boolean directed = scanner.nextBoolean();

        AdjacencyListGraph graph = new AdjacencyListGraph(V, directed);

        System.out.print("Enter number of edges: ");
        int E = scanner.nextInt();

        System.out.println("Enter edges (u v):");
        for (int i = 0; i < E; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.addEdge(u, v);
        }

        graph.printGraph();
        scanner.close();
    }
}
