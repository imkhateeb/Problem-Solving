# 📚 Floyd-Warshall Algorithm – All Pairs Shortest Path

The **Floyd-Warshall Algorithm** is a **dynamic programming** algorithm used to find the **shortest paths between all pairs of vertices** in a **weighted graph**, including graphs with **negative weights** (but **no negative cycles**).

---

## 📖 1. Theory: What is Floyd-Warshall Algorithm?

Floyd-Warshall solves the **all-pairs shortest path** problem by considering all nodes as potential **intermediate nodes** in the shortest path between every pair of vertices.

### ✅ Key Characteristics:
- Works with **negative edge weights** ❗
- **Cannot handle negative weight cycles**
- Uses a **3D DP-like approach** over a 2D matrix

---

## 🧠 Core Idea:

> For every pair of vertices `i → j`, check if going through an intermediate node `k` is shorter:  
> `if (dist[i][j] > dist[i][k] + dist[k][j]) → update dist[i][j]`

This is repeated for **each node `k`** as an intermediate.

---

## 🔁 2. Floyd-Warshall Algorithm – Step-by-Step

### 🚀 Steps:
1. Initialize a `dist[V][V]` matrix:
   - `dist[i][j] = weight` of edge `i → j`
   - If no direct edge: `dist[i][j] = INF` (except `dist[i][i] = 0`)
2. For each intermediate node `k` from `0` to `V-1`:
   - For every node `i`:
     - For every node `j`:
       - Update:  
         `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`

---

## ⏱ Time and Space Complexity

| Complexity      | Value           |
|----------------|------------------|
| Time           | `O(V^3)`         |
| Space          | `O(V^2)`         |

---

## ⚠️ 3. Detecting Negative Cycles

After running the main algorithm, if **`dist[i][i] < 0`** for any `i`, a **negative weight cycle** exists in the graph.

---

## 📌 Example Dry Run

**Input Graph:**
0 → 1 (3)
0 → 2 (8)
1 → 2 (2)
2 → 3 (1)
3 → 0 (4)


### 🟩 Initial Matrix

> `dist[i][j] = weight(i → j), INF if no edge`

| From \ To | 0     | 1     | 2     | 3     |
|-----------|-------|-------|-------|-------|
| **0**     | 0     | 3     | 8     | INF   |
| **1**     | INF   | 0     | 2     | INF   |
| **2**     | INF   | INF   | 0     | 1     |
| **3**     | 4     | INF   | INF   | 0     |

---

### 🟦 Final Output (After Floyd-Warshall)

| From \ To | 0     | 1     | 2     | 3     |
|-----------|-------|-------|-------|-------|
| **0**     | 0     | 3     | 5     | 6     |
| **1**     | 6     | 0     | 2     | 3     |
| **2**     | 5     | 8     | 0     | 1     |
| **3**     | 4     | 7     | 9     | 0     |


---

## 🔄 4. Floyd-Warshall vs Dijkstra vs Bellman-Ford

| Feature                    | Floyd-Warshall        | Dijkstra               | Bellman-Ford          |
|----------------------------|------------------------|------------------------|------------------------|
| Use-case                   | All-pairs              | Single-source          | Single-source          |
| Time Complexity            | `O(V^3)`               | `O((V + E) log V)`     | `O(V * E)`             |
| Handles Negative Weights   | ✅ Yes                 | ❌ No                  | ✅ Yes                 |
| Detects Negative Cycles    | ✅ Yes                 | ❌ No                  | ✅ Yes                 |
| Graph Type                 | Weighted (no cycles)   | Weighted (non-neg)     | Weighted (w/ neg)      |

---

## 🧠 Pro Tips

- Use Floyd-Warshall when:
  - You need **shortest path between all pairs**
  - Graph has **small V (≤ 400)** and can contain **negative weights**
- Use Dijkstra for **single-source** and non-negative edge weights
- Check `dist[i][i]` after algorithm to detect **negative cycles**

---

## 🔗 Related Leetcode / CP Problems

- 🔗 [Leetcode 1334 – Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)
- 🔗 [GFG – Floyd Warshall](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)

---

## ✅ Sample C++ Code

```cpp
void floydWarshall(vector<vector<int>>& dist, int V) {
    // dist[i][j] = initial weight between i and j
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative Weight Cycle Detected\n";
            return;
        }
    }

    // Output distance matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
```

## 📎 Input Format
- Input as adjacency matrix
- Replace missing edges with INT_MAX

- Example:
```cpp
vector<vector<int>> dist = {
    {0,   3,   8, INT_MAX},
    {INT_MAX, 0, 2, INT_MAX},
    {INT_MAX, INT_MAX, 0, 1},
    {4, INT_MAX, INT_MAX, 0}
};
```