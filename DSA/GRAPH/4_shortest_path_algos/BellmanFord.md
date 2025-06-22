# 📚 Bellman-Ford Algorithm – Single Source Shortest Path

The **Bellman-Ford Algorithm** is a powerful algorithm to compute the **shortest paths** from a **single source** vertex to all other vertices in a **weighted graph**, even if the graph contains **negative weight edges**.

---

## 📖 1. Theory: What is Bellman-Ford Algorithm?

The Bellman-Ford algorithm works by **relaxing all edges** up to `V - 1` times, where `V` is the number of vertices.

### ✅ Key Characteristics:
- Works for **graphs with negative weights**
- Can **detect negative weight cycles**
- Slower than Dijkstra but more **robust**

---

## 🧠 Core Idea (Relaxation):

> For every edge `u → v` with weight `wt`,  
> if `dist[u] + wt < dist[v]`, then update `dist[v] = dist[u] + wt`.

Repeat the above for all edges **V - 1** times (because the longest possible path without a cycle in a graph with `V` nodes is `V - 1`).

---

## 🔁 2. Bellman-Ford Algorithm – Step-by-Step

### 🚀 Steps:
1. Initialize distance of all nodes as `INF`, except `src` = `0`.
2. Repeat **V - 1 times**:
   - For each edge `u → v`:
     - If `dist[u] + wt < dist[v]` → update `dist[v]`
3. Run one more loop (V-th iteration) to check for **negative weight cycles**:
   - If any edge still allows `dist[v]` to decrease → negative cycle exists.

---

## ⏱ Time and Space Complexity

| Complexity      | Value           |
|----------------|------------------|
| Time           | `O(V * E)`       |
| Space          | `O(V)`           |

---

## ⚠️ 3. Detecting Negative Weight Cycles

If after `V - 1` relaxations, **a further update is still possible**, that implies:
- There's a **cycle** with a total negative weight
- Bellman-Ford can be used to detect such cycles

---

## 📌 Example Dry Run

**Graph Edges:**

Edges:
A → B (4)
A → C (5)
B → C (-3)
C → D (3)

Source: A


### ✅ Relaxations:

| Iteration | dist[] Update                                   |
|-----------|--------------------------------------------------|
| Init      | A=0, B=∞, C=∞, D=∞                              |
| Pass 1    | B=4, C=5, D=∞                                   |
| Pass 2    | C=1 (via B), D=4                                |
| Pass 3    | No further updates                              |
| Pass 4    | Check for negative cycle → No updates → ✅ Safe |

---

## 🔄 4. Bellman-Ford vs Dijkstra

| Feature                    | Bellman-Ford           | Dijkstra (PQ)         |
|----------------------------|------------------------|------------------------|
| Negative weights allowed   | ✅ Yes                 | ❌ No                  |
| Detects negative cycles    | ✅ Yes                 | ❌ No                  |
| Time Complexity            | O(V * E)               | O((V + E) * log V)     |
| Best for                   | Arbitrary weights      | Non-negative weights   |
| Algorithm type             | Dynamic Programming    | Greedy                 |

---

## 🧠 Pro Tips

- Use Bellman-Ford when:
  - Your graph contains **negative weights**
  - You need to **detect cycles** affecting shortest paths
- Prefer **Dijkstra** for **dense or non-negative** graphs (more efficient)
- **Don't use BFS** or Dijkstra when edge weights are negative

---

## 🔗 Related Leetcode / CP Problems

- 🔗 [Leetcode 787 – Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- 🔗 [Codeforces – Negative Cycle Detection Problems](https://codeforces.com/)

---

## ✅ Sample C++ Code

```cpp
vector<int> bellmanFord(int V, int src, vector<vector<int>>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 1: Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 2: Check for negative weight cycle
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative Weight Cycle Detected!\n";
            return {};
        }
    }

    return dist;
}
```

## 📎 Input Format for Graph
- Input as edge list: each edge is `{u, v, weight}`

- Example:

```cpp
vector<vector<int>> edges = {
    {0, 1, 4},
    {0, 2, 5},
    {1, 2, -3},
    {2, 3, 3}
};
```