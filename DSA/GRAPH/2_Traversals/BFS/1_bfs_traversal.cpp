#include <iostream>
#include <vector>
#include <queue>
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
        adj[v].push_back(u); // Undirected
    }

    void BFS() {
        vector<bool> visited(V, false);
        cout << "BFS Traversal: ";

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cout << node << " ";

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4); // Disconnected component

    /*
    Dry Run:

    Components:
    0 - 1 - 2  3 - 4  5

    BFS Output:
    0 1 2 3 4 5 (visited level-wise, starting from each unvisited node)
    */

    g.BFS();
    return 0;
}

/*
Time Complexity: O(V + E)
- Each vertex and edge is visited once

Space Complexity: O(V)
- visited[] + queue
*/
