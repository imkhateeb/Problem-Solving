#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    vector<int> topView(Node *root)
    {

        vector<int> ans;

        map<int, int> mp;

        queue<pair<Node *, int>> nodes;

        nodes.push({root, 0});

        while (!nodes.empty())
        {

            Node *node = nodes.front().first;
            int line = nodes.front().second;
            nodes.pop();
            if (mp.find(line) == mp.end())
            {
                mp[line] = node->data;
            }

            if(node -> left) nodes.push({node -> left, line-1});
            if(node -> right) nodes.push({node -> right, line+1});
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
        solution.topView(root);

    // Print the result
    cout << "Top View Traversal: " << endl;
    for (auto node : topView)
    {
        cout << node << " ";
    }

    return 0;
}