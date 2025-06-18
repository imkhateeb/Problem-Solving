#include <bits/stdc++.h>

/**
 * ✅ Leetcode 130: Surrounded Regions
 * 🔗 https://leetcode.com/problems/surrounded-regions/
 * 
 * 📌 Problem Statement:
 * - Given a 2D board with 'X' and 'O', capture all regions surrounded by 'X'.
 * - Flip all 'O's that are fully surrounded by 'X' into 'X'.
 * - But do not flip any 'O' that is connected to the border (directly or indirectly).
 * 
 * 🧠 Intuition:
 * - Any 'O' **not connected to a boundary** must be surrounded by 'X' and hence should be flipped.
 * - So we only want to preserve 'O's **connected to the border**.
 * 
 * ✅ Approach:
 * 1. Traverse all 4 borders of the matrix.
 * 2. For each 'O' on the border, run DFS and mark all connected 'O's with a temporary marker ('A').
 * 3. In the end:
 *     - Convert 'A' → 'O' (not surrounded)
 *     - Convert 'O' → 'X' (surrounded)
 * 
 * 🔁 Dry Run:
 * Input:
 *   X X X X
 *   X O O X
 *   X X O X
 *   X O X X
 * 
 * DFS starts from (3,1) → connected to border → mark as 'A'
 * → final result:
 *   X X X X
 *   X X X X
 *   X X X X
 *   X O X X
 * 
 * ⏱ Time Complexity: O(m × n)
 * 🧠 Space Complexity: O(m × n) [due to recursion stack in worst case]
 * 
 * 🔗 Similar Problems:
 * - 200. Number of Islands
 * - 694. Number of Distinct Islands
 * - 733. Flood Fill
 */

class Solution {
private:
    // ⬅️ ➡️ ⬇️ ⬆️ directions
    int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    // DFS to mark all 'O's connected to border
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board) {
        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 'O') {
                board[ni][nj] = 'A'; // temporary mark
                dfs(ni, nj, n, m, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Step 1: DFS from all border 'O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check only borders
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'A'; // temporary marker
                        dfs(i, j, n, m, board);
                    }
                }
            }
        }

        // Step 2: Flip inner surrounded 'O' to 'X' and restore 'A' to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O'; // restore safe 'O'
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // surrounded → flip to 'X'
                }
            }
        }
    }
};
