#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    bool directed;
    bool weighted;
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph(int vertices, bool isDirected = false, bool isWeighted = false) {
        V = vertices;
        directed = isDirected;
        weighted = isWeighted;

        // Initialize matrix with 0 (no edge)
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Function to add an edge
    void addEdge(int u, int v, int weight = 1) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex number.\n";
            return;
        }

        if (!weighted) weight = 1;

        adjMatrix[u][v] = weight;

        // If the graph is undirected, also add edge from v to u
        if (!directed) {
            adjMatrix[v][u] = weight;
        }
    }

    // Function to display the adjacency matrix
    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    bool isDirected = false;
    bool isWeighted = false;

    Graph g(vertices, isDirected, isWeighted);

    // Add some edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Display the matrix
    g.display();

    return 0;
}
