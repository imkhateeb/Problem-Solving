#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    void DFS() {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4); // disconnected component

    /*
    Dry Run:

    Graph Components:
    0 - 1 - 2      3 - 4    5

    DFS Traversal (from 0): 0 1 2 3 4 5
    - Starts at node 0 → goes deep into 1, then 2
    - Then moves to 3 → 4
    - Finally visits 5 (isolated)
    */

    g.DFS();
    return 0;
}

/*
Time Complexity: O(V + E)
- V = vertices, E = edges
- Each vertex is visited once
- Each edge is considered once

Space Complexity: O(V)
- visited[] array + recursive call stack (in worst case)
*/
