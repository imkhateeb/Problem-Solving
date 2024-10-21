#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

Node *buildTree(Node *root)
{
  int data;
  if (!root)
  {
    cout << "Enter root data: ";
  }
  cin >> data;

  if (data == -1)
  {
    return NULL;
  }

  root = new Node(data);

  cout << "Enter left child of: " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter right child of: " << data << endl;
  root->right = buildTree(root->right);

  return root;
}

void levelOrderTraversal(Node *root)
{
  if (!root)
  {
    cout << "Tree is empty!" << endl;
    return;
  }

  queue<Node *> q;

  q.push(root);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    cout << temp->data << " ";

    if (temp->left)
    {
      q.push(temp->left);
    }
    if (temp->right)
    {
      q.push(temp->right);
    }
  }
}

void inOrderTraversal(Node *root)
{
  if (!root)
  {
    cout << "Tree is empty!" << endl;
    return;
  }

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
  if (!root)
  {
    cout << "Tree is empty!" << endl;
    return;
  }

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
  if (!root)
  {
    cout << "Tree is empty!" << endl;
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

int main()
{
  Node *root = nullptr;

  root = buildTree(root);

  cout << "Level Order Traversal: ";
  levelOrderTraversal(root);
  cout << endl;

  cout << "In Order Traversal: ";
  inOrderTraversal(root);
  cout << endl;

  cout << "Pre Order Traversal: ";
  preOrderTraversal(root);
  cout << endl;

  cout << "Post Order Traversal: ";
  postOrderTraversal(root);
  cout << endl;

  return 0;
}
