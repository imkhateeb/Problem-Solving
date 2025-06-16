#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    bool isDirected;
    vector<vector<int>> adj;

public:
    Graph(int V, bool isDirected) {
        this->V = V;
        this->isDirected = isDirected;
        adj.resize(V);
    }

    // Add edge u -> v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!isDirected)
            adj[v].push_back(u);
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int V, E;
    bool isDirected;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Is the graph directed? (1 for yes, 0 for no): ";
    cin >> isDirected;

    Graph g(V, isDirected);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();
    return 0;
}
