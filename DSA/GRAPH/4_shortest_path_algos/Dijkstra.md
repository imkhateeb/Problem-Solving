# 📚 Dijkstra's Algorithm – Shortest Path in Graphs

Dijkstra's Algorithm is a **greedy** algorithm used to find the **shortest path** from a **single source** to all other nodes in a **weighted graph** with **non-negative edge weights**.

---

## 📖 1. Theory: What is Dijkstra's Algorithm?

Dijkstra's Algorithm solves the **single-source shortest path** problem for a graph with:
- **Vertices (V)**
- **Edges (E)** with **non-negative weights**

### 🧠 Core Idea:
Always expand the **next closest unvisited node**. It works like BFS, but with a priority mechanism based on shortest known distance.

### ✅ Key Features:
- Works on both **directed** and **undirected** graphs
- Only works when **all edge weights ≥ 0**
- Uses a **greedy strategy** to pick the minimum-cost path at every step

---

## 🔁 2. Dijkstra's Algorithm Using Priority Queue (Min-Heap)

### 🚀 Approach:
1. Use a **min-heap priority queue** to get the node with the smallest known distance
2. Keep a `dist[]` array to store the shortest distances from the source
3. For each node, relax its neighbors:
   - `if (dist[u] + wt < dist[v]) → update dist[v]`

### ⏱ Time Complexity:
- `O((V + E) * log V)` (using `priority_queue` as min-heap)

### 📦 Space Complexity:
- `O(V)` for distance array
- `O(V)` for priority queue

### 📌 C++ Code:
```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// pair<distance, node>
pq.push({0, source});
dist[source] = 0;

while (!pq.empty()) {
    int node = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    for (auto [nbr, wt] : adj[node]) {
        if (d + wt < dist[nbr]) {
            dist[nbr] = d + wt;
            pq.push({dist[nbr], nbr});
        }
    }
}
```

## 🔁 3. Dijkstra's Algorithm Using Set (TreeSet equivalent)
### 🚀 Approach:
1. Similar to min-heap but uses a set (balanced BST) to allow O(log N) delete operations
2. If a better distance is found for a node already in the set, remove and re-insert with the new distance

### ⏱ Time Complexity:
O(E * log V) (slightly better in edge cases due to fast updates)

### 📌 C++ Code:
```cpp
set<pair<int, int>> st;
st.insert({0, source});
dist[source] = 0;

while (!st.empty()) {
    auto [d, node] = *st.begin();
    st.erase(st.begin());

    for (auto [nbr, wt] : adj[node]) {
        if (d + wt < dist[nbr]) {
            if (dist[nbr] != INT_MAX) {
                st.erase({dist[nbr], nbr});
            }
            dist[nbr] = d + wt;
            st.insert({dist[nbr], nbr});
        }
    }
}
```

## 🆚 4. Set vs Priority Queue vs Queue

| Feature                  | Set (`std::set`)         | Priority Queue (`std::priority_queue`) | Queue (`std::queue`)         |
|--------------------------|--------------------------|-----------------------------------------|-------------------------------|
| **Time to get min**      | O(log N)                 | O(1) (via `top()`)                      | ❌ Not supported              |
| **Time to remove min**   | O(log N)                 | O(log N)                                | ❌ FIFO only                 |
| **Supports update/delete** | ✅ Yes (`erase` + `insert`) | ❌ No (duplicates cause delay)         | ❌ No                        |
| **Best for**             | Dynamic updates          | Classic Dijkstra                        | BFS (unweighted graphs)      |

### ⚠️ Why Not Use a Normal Queue?

In Dijkstra's algorithm, you must always process the **closest unvisited node next**.  
A normal FIFO queue does **not guarantee this**, which can lead to incorrect results.

---

## 🚫 5. Why Dijkstra Doesn't Work with Negative Weights

### ❌ Negative Weight Problem:
If a graph contains a **negative weight edge**, Dijkstra may:
- **Process a node too early**, assuming its shortest path is known.
- Later discover a **shorter path**, but Dijkstra won’t revisit the node.

As a result, Dijkstra **fails to give the correct shortest paths**.

---

### 🔄 Bellman-Ford to the Rescue:

Use **Bellman-Ford Algorithm** if:
- The graph has **negative edge weights**
- You need to **detect negative weight cycles**

---

## ✅ Summary

| Feature                   | Dijkstra (Priority Queue) | Dijkstra (Set)     | Bellman-Ford        |
|---------------------------|----------------------------|---------------------|----------------------|
| **Negative weights allowed** | ❌ No                     | ❌ No               | ✅ Yes               |
| **Cycle detection**        | ❌ No                     | ❌ No               | ✅ Yes               |
| **Min update flexibility** | ❌ No                     | ✅ Yes              | ✅ Yes               |
| **Best use-case**          | Non-negative edges        | Dynamic updates     | Negative edge paths  |

---

## 🔗 Related Leetcode Problems

- 🔗 [743 – Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- 🔗 [1631 – Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
- 🔗 [1514 – Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)
- 🔗 [1976 – Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)

---

## 🧠 Pro Tips

- Always initialize `dist[]` with `INT_MAX`
- Use `set` only if you need to **update** distances dynamically
- Never apply Dijkstra on graphs with **negative edge weights**
- For unweighted graphs, use **BFS**
- For all-pairs shortest paths, use **Floyd-Warshall**
