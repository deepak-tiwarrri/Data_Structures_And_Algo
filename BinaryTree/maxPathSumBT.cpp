// find the height of the
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
int maxDepth(TreeNode *root)
{
   if (!root)
      return 0;
   int lh = maxDepth(root->left);
   int rh = maxDepth(root->right);
   return 1 + max(lh, rh);
}
int maxPathSum(TreeNode *root, int &maxiSum)
{
   if (!root)
      return 0;
   // only take the leftsum don't take the negative value
   int leftSum = max(0, maxPathSum(root->left, maxiSum));
   int rightSum = max(0, maxPathSum(root->right, maxiSum));
   maxiSum = max(maxiSum, root->data + leftSum + rightSum);
   return root->data + max(leftSum, rightSum);
}
int main()
{
   // code here
   // 1

   /*
           1
          / \
         2   3
        / \ /
       4  9 9
   */
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(9);
   root->right->left = new TreeNode(9);
   int maxiSum = INT_MIN;
   int res = maxPathSum(root, maxiSum);
   cout << maxiSum << endl;

   return 0;
}