#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Alien Dictionary using Topological Sort (DFS)
 * 📌 Problem: Given a sorted list of words from an alien dictionary,
 *             find the order of characters.
 * 🔗 Related: https://leetcode.com/problems/alien-dictionary/
 * 
 * 🧠 Intuition:
 * - Extract ordering constraints from word pairs (edges: u → v)
 * - Build graph and apply DFS-based topological sort
 * - Use a `visited` map and a `recursionStack` to detect cycles
 * 
 * ✅ Approach:
 * 1. Build the graph by comparing adjacent words.
 * 2. Perform DFS with onStack (recursion stack) to detect cycles.
 * 3. Push characters to stack after visiting all their neighbors (post-order).
 * 
 * 🔁 Dry Run:
 * Words = {"caa", "aaa", "aab"}
 * Edges:
 *   c → a
 *   a → b
 * Order = c a b
 * 
 * ⏱ Time Complexity: O(N * L + V + E)
 *   - N = number of words, L = average word length
 *   - V = unique characters, E = constraints (edges)
 * 🧠 Space Complexity: O(V + E)
 */

class Solution {
public:
    bool dfs(char node,
             unordered_map<char, vector<char>>& adj,
             unordered_map<char, bool>& visited,
             unordered_map<char, bool>& onStack,
             stack<char>& st) {

        visited[node] = true;
        onStack[node] = true;

        for (char neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (!dfs(neighbor, adj, visited, onStack, st)) {
                    return false; // cycle detected
                }
            } else if (onStack[neighbor]) {
                return false; // back edge → cycle
            }
        }

        onStack[node] = false;
        st.push(node); // post-order
        return true;
    }

    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_set<char> allChars;

        // Step 1: Register all unique characters
        for (const string& word : words) {
            for (char ch : word) {
                allChars.insert(ch);
                adj[ch]; // ensure the key exists
            }
        }

        // Step 2: Build constraints from word pairs
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());

            bool found = false;
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]); // w1[j] → w2[j]
                    found = true;
                    break;
                }
            }

            // Invalid if w1 is longer but a prefix of w2 (e.g. "abc", "ab")
            if (!found && w1.length() > w2.length()) {
                return "";
            }
        }

        // Step 3: DFS Topological Sort
        unordered_map<char, bool> visited;
        unordered_map<char, bool> onStack;
        stack<char> st;

        for (char ch : allChars) {
            if (!visited[ch]) {
                if (!dfs(ch, adj, visited, onStack, st)) {
                    return ""; // cycle detected
                }
            }
        }

        // Step 4: Build result string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    vector<string> words = {"caa", "aaa", "aab"};

    Solution sol;
    string order = sol.alienOrder(words);

    if (order.empty()) {
        cout << "Invalid input: Cycle detected or prefix conflict.\n";
    } else {
        cout << "Alien Dictionary Order (DFS): " << order << endl;
    }

    return 0;
}
