#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        if (!root)
        {
            return ans;
        }

        map<int, int> mp;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            Node *node = q.front().first;
            int line = q.front().second;

            q.pop();

            mp[line] = node->data;

            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =
        solution.bottomView(root);

    // Print the result
    cout << "Top View Traversal: " << endl;
    for (auto node : topView)
    {
        cout << node << " ";
    }

    return 0;
}