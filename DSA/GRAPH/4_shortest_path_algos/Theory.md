# 📚 Shortest Path Algorithms in Graphs

Shortest path algorithms are fundamental in graph theory used to find the minimum cost or distance between nodes.

---

## 📖 What is the Shortest Path Problem?

The **shortest path problem** involves finding the **minimum-weight path** between two vertices (or from a source to all vertices) in a **weighted graph**.

---

## ⚠️ Key Considerations

- Graphs can be:
  - **Directed / Undirected**
  - **Weighted / Unweighted**
- Edge weights may be:
  - **Non-negative**
  - **Negative** (may require special handling)

---

## 🔁 Algorithms for Shortest Path

---

### 🔸 1. **Dijkstra’s Algorithm**

#### ✅ Use Case:
- **Graphs with non-negative weights**

#### 🚀 Steps:
1. Initialize a distance array with `INT_MAX`, except source as 0.
2. Use a **min-heap (priority queue)** to select the minimum distance node.
3. For each neighbor, if a shorter path is found, update the distance.
4. Repeat until all nodes are processed.

#### ⏱ Time Complexity:
- **O((V + E) log V)** with min-heap

#### 🧠 Space Complexity:
- O(V) for distance array and min-heap

#### ⚠️ Limitations:
- Doesn’t work with **negative weight edges**

---

### 🔸 2. **Bellman-Ford Algorithm**

#### ✅ Use Case:
- Graphs with **negative weights**, but **no negative cycles**

#### 🚀 Steps:
1. Initialize distance of all nodes to `∞`, source as 0.
2. Repeat `V - 1` times:
   - Relax all edges: `if dist[u] + wt < dist[v] → update dist[v]`
3. After that, do **one more pass**:
   - If any distance updates, a **negative cycle exists**

#### ⏱ Time Complexity:
- **O(V * E)**

#### 🧠 Space Complexity:
- O(V) for distance array

#### ⚠️ Detects negative cycles

---

### 🔸 3. **Floyd-Warshall Algorithm**

#### ✅ Use Case:
- **All pairs shortest paths** (dense graphs)

#### 🚀 Steps:
1. Create a 2D matrix `dist[i][j]` initialized with edge weights (or `INF`).
2. For each node `k`:
   - Update `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
3. After V iterations → shortest paths between all node pairs

#### ⏱ Time Complexity:
- **O(V³)**

#### 🧠 Space Complexity:
- O(V²)

#### ⚠️ Detects negative cycles (if `dist[i][i] < 0`)

---

### 🔸 4. **0-1 BFS**

#### ✅ Use Case:
- Graphs with **edge weights 0 or 1** only

#### 🚀 Steps:
1. Use a **double-ended queue (deque)**
2. Push edge with weight 0 to **front**, weight 1 to **back**
3. Works faster than Dijkstra for 0-1 edge weights

#### ⏱ Time Complexity:
- **O(V + E)**

#### 🧠 Space Complexity:
- O(V)

---

## ✅ Use Cases

- **GPS navigation** (Dijkstra)
- **Currency arbitrage detection** (Bellman-Ford)
- **Network routing protocols**
- **Social networks** (unweighted → BFS)
- **0-1 Knapsack on graphs** (0-1 BFS)

---

## 🧪 Example Weighted Graph

**Edges:**
0 → 1 (4)
0 → 2 (1)
2 → 1 (2)
1 → 3 (1)
2 → 3 (5)

---

### 📋 Adjacency List

0: (1, 4), (2, 1)
1: (3, 1)
2: (1, 2), (3, 5)
3: -

---

### ✅ Shortest Path from Node 0

- **Dijkstra Output:** 0 → 2 → 1 → 3  
- **Distances:** `[0, 3, 1, 4]`

---

## ⚠️ Negative Cycle Detection

- **Bellman-Ford:** Can detect cycle by checking updates in `V-th` iteration  
- **Floyd-Warshall:** If `dist[i][i] < 0` → negative cycle

---

## 🧠 Summary Table

| Feature               | Dijkstra          | Bellman-Ford      | Floyd-Warshall     | 0-1 BFS           |
|-----------------------|------------------|-------------------|--------------------|-------------------|
| Graph Type            | Weighted, no neg | Weighted + neg OK | Dense, all-pairs   | 0/1 weighted      |
| Handles Neg Weights   | ❌ No             | ✅ Yes            | ✅ Yes             | ❌ No             |
| Detects Neg Cycles    | ❌ No             | ✅ Yes            | ✅ Yes             | ❌ No             |
| Time Complexity        | O((V + E) log V) | O(V * E)          | O(V³)              | O(V + E)          |
| Space Complexity       | O(V + E)         | O(V)              | O(V²)              | O(V)              |
| Output                | Source to all     | Source to all     | All-pairs          | Source to all     |

---

## 🔗 Related Leetcode Problems

- 🔗 [743 – Network Delay Time (Dijkstra)](https://leetcode.com/problems/network-delay-time/)
- 🔗 [787 – Cheapest Flights Within K Stops (Bellman-Ford)](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- 🔗 [1334 – Find City with Smallest Neighbors (Floyd-Warshall)](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)
- 🔗 [1129 – Shortest Path with Alternating Colors (0-1 BFS)](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

---

## 🚀 Pro Tips

- Use **Dijkstra** when all weights are positive  
- Use **Bellman-Ford** if graph can have **negative edges**  
- Use **Floyd-Warshall** only for **small graphs**  
- Use **0-1 BFS** for **binary-weighted** graphs (0/1)  
- For **unweighted graphs**, just use **BFS**
