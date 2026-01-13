#include <bits/stdc++.h>
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
bool isSameTree(TreeNode *p, TreeNode *q)
{
   // code here
   if (p == nullptr || q == nullptr)
   {
      return p == q;
   }
   return (p->data == q->data) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}
int main()
{

   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(9);
   root->right->left = new TreeNode(9);
   root->right->left->right = new TreeNode(10);
   root->left->left->right = new TreeNode(5);
   root->left->left->right->right = new TreeNode(6);
   return 0;
}