# 📚 Disjoint Set (Union-Find)

The **Disjoint Set** (also called **Union-Find**) is a data structure that keeps track of elements partitioned into a number of **disjoint (non-overlapping) sets**.

It supports two main operations efficiently:
- `Find`: Determine which set an element belongs to
- `Union`: Merge two sets

---

## 📖 1. Why Use Disjoint Set?

Used in scenarios where we need to:
- Keep track of **connected components**
- **Merge** sets and **check if two elements are in the same set**
- Solve problems involving **cycle detection**, **Kruskal’s algorithm**, **friend circles**, etc.

---

## 🧠 2. Core Operations

| Operation | Description                          |
|----------|--------------------------------------|
| `find(u)`  | Returns the representative (root) of the set containing `u` |
| `union(u, v)` | Merges the sets containing `u` and `v` |

---

## 🔧 3. Implementation Enhancements

### 🔹 Path Compression (in `find`)
- Makes the tree flat by attaching nodes directly to the root.
- Helps speed up future `find()` calls.

### 🔹 Union by Rank / Size
- Attach the **smaller tree** under the **larger tree** to reduce height.

---

## 🧠 4. Time and Space Complexity

| Operation     | Time Complexity |
|---------------|-----------------|
| `find()`      | `O(α(N))` (almost constant) |
| `union()`     | `O(α(N))` (inverse Ackermann function) |
| Space         | `O(N)`          |

> ⚠️ `α(N)` is very slow-growing; practically ≤ 4 even for large `N`

---

## 🚀 5. Use Cases

- **Cycle Detection in Graphs**
- **Kruskal’s MST Algorithm**
- **Connected Components**
- **Network connectivity problems**
- **Dynamic connectivity queries**

---

## 🧪 6. Example Dry Run

Initial elements: `{0}, {1}, {2}, {3}, {4}`

```txt
Union(0, 1) → {0,1}
Union(2, 3) → {2,3}
Union(1, 3) → {0,1,2,3}
Find(3)     → 0 (leader/root)
```

---

## 🧠 7. Disjoint Set Variants

| Variant            | Description                                      |
|--------------------|--------------------------------------------------|
| **Union by Rank**  | Track tree height to keep it shallow             |
| **Union by Size**  | Track size of set and attach the smaller set     |
| **Path Compression** | Attach nodes directly to root during `find()` |
| **Persistent DSU** | For history tracking (advanced use-cases)        |

---

## ✅ 8. C++ Code (with Path Compression + Union by Rank)

```cpp
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
```

---

## ✅ 9. C++ Code (Union by Size)

```cpp
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
```

---

### 🔗 10. Related Problems

- [🔗 GFG – Disjoint Set (Union-Find)](https://www.geeksforgeeks.org/disjoint-set-data-structures/)
- [🔗 Leetcode 547 – Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
- [🔗 Leetcode 1319 – Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
- [🔗 Leetcode 990 – Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)
- [🔗 Leetcode 684 – Redundant Connection](https://leetcode.com/problems/redundant-connection/)
- [🔗 Leetcode 261 – Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)

---

### 🧠 Pro Tips

- ✅ Use **union by rank** or **union by size** + **path compression** for optimal performance  
- ⚠️ When implementing **Kruskal’s Algorithm**, Disjoint Set is essential to detect **cycles**  
- ❌ Avoid reinitializing `parent[]` or `rank[]` inside loops — initialize **once in the constructor**
