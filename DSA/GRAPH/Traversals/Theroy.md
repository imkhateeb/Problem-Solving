# 📚 DFS and BFS Traversal in Graphs

Graphs can be traversed using two fundamental algorithms:
- **DFS (Depth-First Search)**
- **BFS (Breadth-First Search)**

---

## 🔍 Depth-First Search (DFS)

### 🔁 Algorithm (recursive)

1. Start from a source node
2. Mark the node as visited
3. Recursively visit all **unvisited** neighbors

### 🔁 Algorithm (iterative with stack)

1. Push source node to stack
2. While stack is not empty:
   - Pop a node and mark it as visited
   - Push all unvisited neighbors onto the stack

### ⏱️ Time Complexity
- **O(V + E)**  
(V = vertices, E = edges)

### 🧠 Space Complexity
- O(V) for visited array
- O(V) call stack (recursive) or stack (iterative)

### ✅ Use Cases
- Detect cycles in graphs
- Topological sorting (in DAG)
- Maze/connected component solving

---

## 🔎 Breadth-First Search (BFS)

### 🔁 Algorithm

1. Enqueue source node
2. Mark it as visited
3. While queue is not empty:
   - Dequeue a node
   - Visit and enqueue all unvisited neighbors

### ⏱️ Time Complexity
- **O(V + E)**

### 🧠 Space Complexity
- O(V) for visited array
- O(V) for queue

### ✅ Use Cases
- Find shortest path in **unweighted graphs**
- Level-order traversal
- Bipartite checking

---

## 🧪 Example Graph (Undirected)
0 --- 1 --- 2
|           |
4 --------- 3


### 📋 Adjacency List Representation
0: 1, 4  
1: 0, 2  
2: 1, 3  
3: 2, 4  
4: 0, 3


### 🔁 DFS Traversal (starting from 0)

**Order** (may vary):  
`0 → 1 → 2 → 3 → 4`

### 🔁 BFS Traversal (starting from 0)

**Order**:  
`0 → 1 → 4 → 2 → 3`

---

## 🧠 Summary Table

| Feature            | DFS                         | BFS                         |
|--------------------|-----------------------------|-----------------------------|
| Data Structure     | Stack / Recursion           | Queue                       |
| Traversal Style    | Depth-first                 | Level-wise (breadth-first) |
| Time Complexity    | O(V + E)                    | O(V + E)                    |
| Space Complexity   | O(V)                        | O(V)                        |
| Applications       | Cycle detection, Topo sort  | Shortest path, Bipartiteness |

---

## 🚀 Pro Tip

- Use **DFS** when you're okay going deep and backtracking  
- Use **BFS** when shortest path or level order matters

---