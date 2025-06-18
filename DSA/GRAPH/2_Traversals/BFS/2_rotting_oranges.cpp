#include <bits/stdc++.h>
using namespace std;


/**
 * ✅ Problem Link: https://leetcode.com/problems/rotting-oranges/
 *
 * 🧠 Intuition:
 * - Each rotten orange (2) rots its 4-directionally adjacent fresh orange (1) in 1 minute.
 * - This is a **multi-source BFS** where all rotten oranges spread in parallel.
 * - We track the time taken to rot each fresh orange.
 *
 * ❓ Goal:
 * - Return the minimum number of minutes needed to rot all fresh oranges.
 * - If it's not possible, return -1.
 *
 * 🔁 Dry Run:
 * Input:
 *   grid = [
 *     [2, 1, 1],
 *     [1, 1, 0],
 *     [0, 1, 1]
 *   ]
 *
 * Minute 0: Start from (0,0)
 * Minute 1: (0,1), (1,0) rot
 * Minute 2: (0,2), (1,1) rot
 * Minute 3: (2,1) rots
 * Minute 4: (2,2) rots
 * → Answer: 4
 *
 * 🔍 Why BFS:
 * - BFS spreads level-by-level → exactly matches the way rot spreads per minute.
 * - Ensures minimum time is calculated for each orange.
 *
 * ❌ Why not DFS:
 * - DFS does not naturally simulate simultaneous spread.
 * - Cannot easily track the minimum time from multiple sources.
 *
 * ❌ Why not brute-force simulation:
 * - Inefficient. You'd loop over the grid again and again for each minute.
 * - Higher time complexity and harder to manage state.
 *
 * ⏱ Time Complexity:
 * - O(m × n) → Every cell is processed once
 *
 * 🧠 Space Complexity:
 * - O(m × n) → In worst case, all cells could be in the queue
 *
 * 🔗 Similar Leetcode Problems:
 * - 286. Walls and Gates (BFS from gates) - https://leetcode.com/problems/walls-and-gates/description/
 * - 542. 01 Matrix (BFS from 0s) - https://leetcode.com/problems/01-matrix/description/
 * - 1091. Shortest Path in Binary Matrix - https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 * - 847. Shortest Path Visiting All Nodes - https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();     // rows
        int m = grid[0].size();  // columns

        queue<tuple<int, int, int>> q; // BFS queue: {minute, row, col}
        int totalFresh = 0;            // Count of fresh oranges

        // 🔄 Step 1: Initialize queue with all rotten oranges & count fresh
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(0, i, j); // time = 0 for all rotten oranges
                } else if (grid[i][j] == 1) {
                    totalFresh++;      // count fresh oranges
                }
            }
        }

        // ⬆️⬇️⬅️➡️ directions for adjacent cells
        int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int minutes = 0;

        // 🌀 Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [t, i, j] = q.front(); q.pop(); // current time, row, col
            minutes = t; // update the last time seen (max time to rot)

            for (auto& dir : directions) {
                int ni = i + dir[0]; // next row
                int nj = j + dir[1]; // next col

                // 🌱 If adjacent cell is fresh, rot it and push to queue
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;       // mark as rotten
                    totalFresh--;           // reduce fresh count
                    q.emplace(t + 1, ni, nj); // rot time +1
                }
            }
        }

        // ✅ Step 3: If all fresh oranges are rotted → return time, else -1
        return totalFresh == 0 ? minutes : -1;
    }
};


// 🧪 Main function to test the solution
int main(){
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution* soln = new Solution();
    int result = soln->orangesRotting(grid);
    cout << "RESULT: " << result << endl; // Expected: 4

    return 0;
}
