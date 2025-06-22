# 📚 Topological Sorting in Graphs

Topological sorting is a fundamental concept in graph theory used in **Directed Acyclic Graphs (DAGs)** to represent dependencies.

---

## 📖 What is Topological Sort?

A **topological sort** of a directed graph is a **linear ordering** of its vertices such that for every **directed edge** `u → v`, vertex `u` comes **before** vertex `v` in the ordering.

---

## ⚠️ Key Conditions

- The graph **must be a DAG** (Directed Acyclic Graph)
- If there’s a cycle → **Topological sort is not possible**

---

## 🔁 Algorithms for Topological Sort

### 🔸 1. **DFS-based Approach**

#### 🚀 Steps:
1. Initialize a visited array
2. For each unvisited node, do a **DFS**
3. In post-order (after visiting all neighbors), **push the node into a stack**
4. Finally, pop all elements from the stack → gives topological order

#### ⏱ Time Complexity:
- **O(V + E)**

#### 🧠 Space Complexity:
- O(V) for visited + recursion stack

---

### 🔸 2. **Kahn’s Algorithm (BFS-based)**

#### 🚀 Steps:
1. Compute **in-degrees** for all nodes
2. Push nodes with `in-degree 0` into a queue
3. While queue is not empty:
   - Pop node, add it to result
   - Decrease in-degree of its neighbors
   - If in-degree becomes 0, add to queue
4. If result contains all nodes → valid topological sort  
   Else → Cycle exists

#### ⏱ Time Complexity:
- **O(V + E)**

#### 🧠 Space Complexity:
- O(V) for queue, in-degree array

---

## ✅ Use Cases

- **Task scheduling** (e.g., course prerequisite problems)
- **Build systems** (e.g., compiling modules in dependency order)
- **Deadlock detection**
- **Package installations**

---

## 🧪 Example Graph

**Directed Edges:**
5 → 0
5 → 2
4 → 0
4 → 1
2 → 3
3 → 1


### 📋 Adjacency List
5: 0, 2
4: 0, 1
2: 3
3: 1


### ✅ Valid Topological Sorts
- `4 5 2 3 1 0`
- `5 4 2 3 1 0`
- Several valid outputs may exist.

---

## 🔁 DFS Topological Sort Output

**Reverse of Post-order:**  
If we add nodes to a stack in post-order, popping it gives the topological sort.

---

## 🔁 Kahn’s Algorithm Output

**BFS-like traversal maintaining in-degrees**

---

## ⚠️ Cycle Detection

- In DFS: If we revisit a node in the current recursion stack → **Cycle**
- In Kahn’s: If the result array has size < V → **Cycle**

---

## 🧠 Summary Table

| Feature              | DFS Topo Sort               | Kahn’s Algo (BFS)          |
|----------------------|-----------------------------|-----------------------------|
| Graph Type           | DAG only                    | DAG only                    |
| Output               | Reverse of post-order DFS   | In-degree based BFS order   |
| Cycle Detection      | Using recursion stack       | Using node count            |
| Time Complexity      | O(V + E)                    | O(V + E)                    |
| Space Complexity     | O(V)                        | O(V)                        |
| Output Uniqueness    | Not guaranteed              | Not guaranteed              |

---

## 🔗 Similar Leetcode Problems

- 🔗 [Leetcode 210 – Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- 🔗 [Leetcode 207 – Course Schedule](https://leetcode.com/problems/course-schedule/)
- 🔗 [Leetcode 269 – Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)

---

## 🚀 Pro Tips

- Always check for **cycles** when doing topological sort
- Use **DFS** for smaller graphs or where recursion is intuitive
- Use **Kahn’s Algorithm** for better debugging and cycle detection
