#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int data, TreeNode *left, TreeNode *right)
   {
      this->data = data;
      this->left = left;
      this->right = right;
   }
   TreeNode(int data)
   {
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
   }
};
TreeNode* findLastRight(TreeNode* root){
  if(root->right==nullptr) return root;
  return findLastRight(root->right);
}
void printInOrder(TreeNode* root){
  if(root==nullptr) return;
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
TreeNode* helper(TreeNode* root){
  if(root->left==nullptr)
    return root->right;
  if(root->right==nullptr)return root->left;
  TreeNode* rightChild = root->right;
  TreeNode *lastRightChild = findLastRight(root->left);
  lastRightChild->right = rightChild;
  return root->left;
}
TreeNode* deleteNodeBST(TreeNode* root, int key){
  if(root==nullptr)
    return root;
  if(root->data==key){
    //means root has to be deleted
    return helper(root);
  }
  TreeNode* dummy = root;

  while(root){
    if(root->data>key){
      //move left and find
      if(root->left!=nullptr && root->left->data==key){
        root->left = helper(root->left);
        break;
      }else{
        root = root->left;
      }
    }else{
      //move right and find
      if(root->right!=nullptr && root->right->data==key){
        root->right = helper(root->right);
        break;
      }else{
        root = root->right;
      }
    }
  }
  return dummy;
}


int main()
{
   // code here
  // TreeNode* root = new TreeNode(5);
  //   root->left = new TreeNode(3);
  //   root->right = new TreeNode(8);
  //   root->left->left = new TreeNode(2);
  //   root->left->right = new TreeNode(4);
   TreeNode *root = new TreeNode(10);
   root->left = new TreeNode(5);
   root->right = new TreeNode(15);
   root->left->left = new TreeNode(2);
   root->left->right = new TreeNode(6);
   root->left->left->left = new TreeNode(1);
   root->left->left->right = new TreeNode(3);
   root->left->right->left = new TreeNode(4);
   root->right->left = new TreeNode(11);
   root->right->right = new TreeNode(17);
   root->right->right->left = new TreeNode(12);
   root->right->right->right = new TreeNode(21);
   
   // Delete node with key 3 from the tree.
   root = deleteNodeBST(root, 5);
   printInOrder(root);

   return 0;
}