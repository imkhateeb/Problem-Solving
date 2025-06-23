# 🌲 Spanning Tree & Minimum Spanning Tree (MST)

A **Spanning Tree** is a subgraph of a connected, undirected graph that includes **all vertices** with the **minimum number of edges** and **no cycles**.

---

## 📖 1. What is a Spanning Tree?

- A **Spanning Tree** connects all vertices using exactly `V - 1` edges
- No cycles (i.e., it’s a tree)
- A graph can have **multiple** spanning trees

### ✅ Properties
| Property                  | Description                              |
|--------------------------|------------------------------------------|
| Number of edges          | Exactly `V - 1`                          |
| Cycles                   | ❌ No cycles                             |
| Connected                | ✅ Yes (all vertices are connected)       |
| Graph type               | Undirected & connected                   |

---

## 💰 2. What is a Minimum Spanning Tree (MST)?

A **Minimum Spanning Tree** is a spanning tree where the **sum of edge weights is minimized**.

### Use-Cases:
- Network design (telecom, internet wiring)
- Circuit layout design
- Approximation algorithms (e.g., TSP)

---

## 🔁 3. Algorithms to Find MST

| Algorithm     | Approach   | Time Complexity | Data Structure Used   |
|---------------|------------|------------------|------------------------|
| **Kruskal’s** | Greedy     | `O(E log E)`     | Union-Find (DSU)       |
| **Prim’s**    | Greedy     | `O(E log V)`     | Min Heap / Priority Queue |
| **Borůvka’s** | Component-based | Varies     | Disjoint Sets          |

---

## 🧠 4. Prim’s Algorithm – Detailed Guide

Prim’s algorithm builds the MST **one node at a time**, always picking the **minimum weight edge** that connects a visited node to an unvisited one.

---

### 🚀 Steps (Using Priority Queue / Min-Heap):

1. Initialize all keys (min edge weights) to `INF`, parent to `-1`
2. Set `key[src] = 0`, push `(0, src)` to the min-heap
3. While heap is not empty:
   - Pop the node with minimum key (weight)
   - For all adjacent nodes not in MST:
     - If edge weight < key[nbr], update key & parent, and push to heap
4. After loop, parent array gives MST edges

---

## ⏱ Time and Space Complexity

| Complexity Type  | Value             |
|------------------|------------------|
| Time (Adj List + Min Heap) | `O(E log V)` |
| Space            | `O(V + E)`       |

---

## 🔄 Dry Run Example

**Graph:**

Vertices = 5
Edges =
0 --1--> 1
0 --3--> 3
1 --3--> 2
1 --4--> 4
2 --5--> 4
3 --6--> 4


### 💡 Adjacency List

| Node | Neighbors (with weights)        |
|------|---------------------------------|
| 0    | (1, 1), (3, 3)                  |
| 1    | (0, 1), (2, 3), (4, 4)          |
| 2    | (1, 3), (4, 5)                  |
| 3    | (0, 3), (4, 6)                  |
| 4    | (1, 4), (2, 5), (3, 6)          |

### ✅ MST Using Prim’s (from node 0):

| Edge Added     | Weight |
|----------------|--------|
| 0 - 1          | 1      |
| 1 - 2          | 3      |
| 0 - 3          | 3      |
| 1 - 4          | 4      |

✅ **Total Weight = 1 + 3 + 3 + 4 = 11**

---

## 🧠 Prim’s vs Kruskal’s

| Feature               | Prim’s Algorithm        | Kruskal’s Algorithm     |
|-----------------------|-------------------------|--------------------------|
| Strategy              | Start from one node     | Sort all edges           |
| Data Structure        | Min Heap (PQ)           | Union-Find (DSU)         |
| Best for              | Dense graphs            | Sparse graphs            |
| Cycle detection       | Implicit via visited[]  | Explicit via DSU         |
| Time Complexity       | `O(E log V)`            | `O(E log E)`             |
| Graph Type            | Connected, Undirected   | Connected, Undirected    |

---

## ✅ Summary

- Spanning Tree: Connects all nodes, no cycles, uses V-1 edges
- MST: Spanning tree with minimum total weight
- Use Prim’s when graph is dense
- Use Kruskal’s for edge-centric sparse graphs

---

## 🔗 Related Leetcode / GFG Problems

- 🔗 [GFG – Minimum Spanning Tree](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)
- 🔗 [Leetcode 1584 – Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)
- 🔗 [GFG – Prims Algorithm](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)

---

## ✅ Sample C++ Code (Prim’s Algorithm – Priority Queue)

```cpp
int primMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {key, node}

    int mstWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += key[u];

        for (auto [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    return mstWeight;
}
```

## 📎 Input Format
- Graph input as adjacency list:

```cpp
vector<vector<pair<int, int>>> adj(V);
adj[0].push_back({1, 1});
adj[0].push_back({3, 3});
adj[1].push_back({0, 1});
adj[1].push_back({2, 3});
adj[1].push_back({4, 4});
adj[2].push_back({1, 3});
adj[2].push_back({4, 5});
adj[3].push_back({0, 3});
adj[3].push_back({4, 6});
adj[4].push_back({1, 4});
adj[4].push_back({2, 5});
adj[4].push_back({3, 6});
```