# 📘 Graph Representation in Data Structures

Graphs represent relationships between pairs of objects (nodes/vertices).  
Each connection is called an **edge**.

---

## 🔰 Types of Graphs

- **Directed Graph (Digraph)**: Edge has direction (u → v)
- **Undirected Graph**: Edge has no direction (u — v)
- **Weighted Graph**: Each edge has a weight or cost
- **Unweighted Graph**: All edges are equal
- **Sparse Graph**: Few edges (E ≪ V²)
- **Dense Graph**: Many edges (E ≈ V²)
- **Connected Graph**: Exists a path between every pair of vertices.
- **Disconnected Graph**: There is atlease one vertices where there is no path between them.

---

## 📦 Graph Representation Techniques

### 1. **Adjacency Matrix**

- 2D array `V x V` (V = number of vertices)
- `matrix[u][v] = 1` if edge exists, else `0` (or `weight` in weighted graph)
- Symmetric for undirected graphs

#### ✅ Pros:
- Quick edge lookup: O(1)
- Simple to implement

#### ❌ Cons:
- Space-heavy: O(V²)
- Not ideal for sparse graphs

---

### 2. **Adjacency List**

- Array/vector of lists: `adj[u]` contains all neighbors of `u`
- Each list holds adjacent vertices (and weights if needed)

#### ✅ Pros:
- Space-efficient: O(V + E)
- Ideal for sparse graphs
- Easy traversal

#### ❌ Cons:
- Edge lookup: O(degree of node)
- Slightly more complex to implement

---

### 3. **Edge List**

- A list of all edges: each edge as a pair/triplet (u, v) or (u, v, weight)
- Useful for algorithms like Kruskal's

#### ✅ Pros:
- Compact for edge-based processing
- Simple structure

#### ❌ Cons:
- Not efficient for edge lookup or neighbor traversal

---

## 📊 Comparison Table

| Feature            | Adjacency Matrix | Adjacency List | Edge List     |
|--------------------|------------------|----------------|---------------|
| Space Complexity   | O(V²)            | O(V + E)       | O(E)          |
| Edge Lookup        | O(1)             | O(degree)      | O(E)          |
| Best for           | Dense Graphs     | Sparse Graphs  | MST algorithms|
| Easy to Traverse   | No               | Yes            | No            |

---

## ⚙️ Basic Graph Operations (in simple steps)

- **Add edge (u, v)**:
  - Matrix: `matrix[u][v] = 1`
  - List: Append `v` to `adj[u]`
- **Remove edge (u, v)**:
  - Matrix: `matrix[u][v] = 0`
  - List: Remove `v` from `adj[u]`
- **Check edge (u, v)**:
  - Matrix: check if `matrix[u][v] == 1`
  - List: search `v` in `adj[u]`

---

## 💡 When to Use What?

| Use Case                                | Recommended Representation |
|-----------------------------------------|-----------------------------|
| Dense graphs (many edges)               | Adjacency Matrix            |
| Sparse graphs                           | Adjacency List              |
| MST algorithms (like Kruskal’s)         | Edge List                   |
| Need fast edge existence check          | Adjacency Matrix            |
| Need to traverse all neighbors quickly  | Adjacency List              |

---

## 🧠 Final Tips

- Always check if the graph is **dense or sparse** before choosing a representation.
- Matrix = Fast lookups, heavy memory  
- List = Efficient for traversal and memory  
- Edge List = Best for algorithms that sort/process edges

---
