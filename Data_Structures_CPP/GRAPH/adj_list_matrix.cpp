#include <iostream>
#include <vector>
#include <list>

class Graph {
    int V; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list
    std::vector<std::vector<int>> adjMatrix; // Adjacency matrix

public:
    Graph(int V) : V(V), adjList(V), adjMatrix(V, std::vector<int>(V, 0)) {}

    // Add edge for adjacency list
    void addEdgeList(int u, int v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }

    // Add edge for adjacency matrix
    void addEdgeMatrix(int u, int v, bool bidir = true) {
        adjMatrix[u][v] = 1;
        if (bidir) {
            adjMatrix[v][u] = 1;
        }
    }

    // Print adjacency list
    void printAdjList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << "->";
            for (int vertex : adjList[i]) {
                std::cout << vertex << ",";
            }
            std::cout << std::endl;
        }
    }

    // Print adjacency matrix
    void printAdjMatrix() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    // Adding edges to the adjacency list
    g.addEdgeList(0, 1);
    g.addEdgeList(0, 4);
    g.addEdgeList(1, 2);
    g.addEdgeList(1, 3);
    g.addEdgeList(1, 4);
    g.addEdgeList(2, 3);
    g.addEdgeList(3, 4);

    // Adding the same edges to the adjacency matrix
    g.addEdgeMatrix(0, 0);
    g.addEdgeMatrix(0, 1);
    g.addEdgeMatrix(0, 4);
    g.addEdgeMatrix(1, 2);
    g.addEdgeMatrix(1, 3);
    g.addEdgeMatrix(1, 4);
    g.addEdgeMatrix(2, 3);
    g.addEdgeMatrix(3, 4);

    g.printAdjList();   // Print adjacency list
    g.printAdjMatrix(); // Print adjacency matrix

    return 0;
}
