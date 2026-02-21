#include<bits/stdc++.h>
using namespace std;
class TreeNode
{

public:
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int data1, TreeNode *left1, TreeNode *right1)
   {
      data = data1;
      left = left1;
      right = right1;
   }
   TreeNode(int data1)
   {
      data = data1;
      left = nullptr;
      right = nullptr;
   }
};

TreeNode* searchBST(TreeNode* root, int key){
  if(root==nullptr)
    return root;
  while(root!=nullptr){
    if(root->data==key)
      return root;
    else if(root->data>key)
      root = root->left;
    else
      root = root->right;
  }
  return root;
}

int main() {
    // Creating a simple BST for demonstration
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* result = searchBST(root, 2);
    if (result) {
        std::cout << "Node found with value: " << result->data << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    // Clean up memory (omitted for brevity)
    return 0;
}