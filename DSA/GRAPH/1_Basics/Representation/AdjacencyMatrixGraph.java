/*
 * ---------------- THEORY: Adjacency Matrix in Java ----------------
 *
 * An adjacency matrix is a 2D array used to represent a graph.
 * For a graph with V vertices:
 * - matrix[i][j] = 1     --> edge exists from vertex i to j (unweighted)
 * - matrix[i][j] = w     --> edge with weight w exists (weighted)
 * - matrix[i][j] = 0     --> no edge
 *
 * For undirected graphs:
 *   matrix[i][j] = matrix[j][i]
 *
 * Time Complexity:
 *   - Add edge: O(1)
 *   - Check edge: O(1)
 * Space Complexity: O(V^2)
 *
 * Suitable for dense graphs.
 */

import java.util.Scanner;

public class AdjacencyMatrixGraph {
    private int[][] matrix;
    private int vertices;
    private boolean isDirected;
    private boolean isWeighted;

    // Constructor
    public AdjacencyMatrixGraph(int vertices, boolean isDirected, boolean isWeighted) {
        this.vertices = vertices;
        this.isDirected = isDirected;
        this.isWeighted = isWeighted;
        matrix = new int[vertices][vertices]; // initialized to 0 by default
    }

    // Add edge between u and v (with optional weight)
    public void addEdge(int u, int v, int weight) {
        if (!isWeighted)
            weight = 1;
        matrix[u][v] = weight;
        if (!isDirected) {
            matrix[v][u] = weight;
        }
    }

    // Display adjacency matrix
    public void printMatrix() {
        System.out.println("Adjacency Matrix:");
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Main function to demonstrate usage
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = scanner.nextInt();

        System.out.print("Is the graph directed? (true/false): ");
        boolean directed = scanner.nextBoolean();

        System.out.print("Is the graph weighted? (true/false): ");
        boolean weighted = scanner.nextBoolean();

        AdjacencyMatrixGraph graph = new AdjacencyMatrixGraph(V, directed, weighted);

        System.out.print("Enter number of edges: ");
        int E = scanner.nextInt();

        System.out.println("Enter edges (format: u v [weight]):");
        for (int i = 0; i < E; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = weighted ? scanner.nextInt() : 1;
            graph.addEdge(u, v, w);
        }

        graph.printMatrix();
        scanner.close();
    }
}


/*
Example Input:
Enter number of vertices: 4
Is the graph directed? (true/false): false
Is the graph weighted? (true/false): true
Enter number of edges: 3
Enter edges (format: u v [weight]):
0 1 5
1 2 3
2 3 2

Output:
Adjacency Matrix:
0 5 0 0
5 0 3 0
0 3 0 2
0 0 2 0
 */