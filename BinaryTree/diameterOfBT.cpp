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
int findHeight(TreeNode *root, int &diameter)
{
   if (root == nullptr)
      return 0;
   int lh = findHeight(root->left, diameter);
   int rh = findHeight(root->right, diameter);
   diameter = max(diameter, lh + rh);
   return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
   int diameter = 0;
   findHeight(root, diameter);
   return diameter;
}
int main()
{
   // code here
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->right = new TreeNode(5);
   root->left->left = new TreeNode(4);
   int res = diameterOfBinaryTree(root);
   cout << res << endl;
   return 0;
}