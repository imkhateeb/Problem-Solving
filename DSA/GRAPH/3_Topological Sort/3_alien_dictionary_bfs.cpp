#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Alien Dictionary using Kahn's Algorithm (Topological Sort - BFS)
 * 📌 Problem: Given a sorted list of words from an alien dictionary,
 *             find the order of characters.
 * 🔗 Related: https://leetcode.com/problems/alien-dictionary/
 * 
 * 🧠 Intuition:
 * - Extract constraints: For each adjacent word pair, find the first differing char.
 * - Build graph: edge from earlier char → later char.
 * - Apply Kahn's algorithm to find a valid topological order of characters.
 * 
 * ✅ Approach:
 * 1. Extract all unique characters and build an adjacency list.
 * 2. For each adjacent word pair, compare characters to build directed edges.
 * 3. Perform topological sort (BFS using in-degree).
 * 4. If result length != number of unique chars → cycle → invalid.
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
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        unordered_set<char> allChars;

        // Step 1: Register all unique characters
        for (const string& word : words) {
            for (char ch : word) {
                allChars.insert(ch);
                inDegree[ch] = 0; // ensure every character has an entry
            }
        }

        // Step 2: Build graph from word pair constraints
        for (int i = 0; i < words.size() - 1; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());

            bool foundDiff = false;
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    foundDiff = true;
                    break;
                }
            }

            // Edge case: prefix problem ("abc" before "ab") → invalid
            if (!foundDiff && w1.length() > w2.length()) {
                return "";
            }
        }

        // Step 3: Topological Sort using Kahn's Algorithm
        queue<char> q;
        for (char ch : allChars) {
            if (inDegree[ch] == 0) q.push(ch);
        }

        string result;
        while (!q.empty()) {
            char ch = q.front(); q.pop();
            result += ch;

            for (char neighbor : adj[ch]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Validate result
        if (result.length() != allChars.size()) {
            return ""; // cycle detected or incomplete ordering
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
        cout << "Alien Dictionary Order: " << order << endl;
    }

    return 0;
}
