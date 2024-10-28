#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
  /* data */

public:
  int data;
  Node *left;
  Node *right;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *buildBinaryTree(Node *root, int data)
{
  if (root == NULL)
  {
    root = new Node(data);
  }
  if (data == -1)
  {
    return NULL;
  }

  cout << "Enter the left child of " << data << " : ";
  int leftData;
  cin >> leftData;
  root->left = buildBinaryTree(root->left, leftData);

  cout << "Enter the right child of " << data << " : ";
  int rightData;
  cin >> rightData;
  root->right = buildBinaryTree(root->right, rightData);

  return root;
}

void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
    cout << temp->data << " ";
    q.pop();

    if (temp->left != NULL)
      q.push(temp->left);
    if (temp->right != NULL)
      q.push(temp->right);
  }
}

int main()
{
  Node *root = NULL;
  int data;
  cout << "Enter the root data : ";
  cin >> data;
  root = buildBinaryTree(root, data);
  levelOrderTraversal(root);

  return 0;
}