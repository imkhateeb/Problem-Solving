#include <Bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

int height(Node* root){
  if ( root == nullptr ) return 0;
}

int main(){
  Node* root = new Node();
  root->data = 1;
  root->left = nullptr;
  root->right = nullptr;

  height(root);
  
  return 0;
}