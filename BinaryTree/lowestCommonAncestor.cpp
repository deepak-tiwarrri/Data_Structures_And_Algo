#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
TreeNode *lowestCommmonAncestor(TreeNode *p, TreeNode *q, TreeNode *root)
{
   if (root == NULL || root == p || root == q)
      return root;

   TreeNode *left = lowestCommmonAncestor(p, q, root->left);
   TreeNode *right = lowestCommmonAncestor(p, q, root->right);

   if (left == nullptr)
   {
      return right;
   }
   else if (right == nullptr)
   {
      return left;
   }
   else
   {
      return root;
   }
}
int main()
{
   // code here
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(2);
   root->left->left = new TreeNode(3);
   root->left->right = new TreeNode(3);
   root->left->left->left = new TreeNode(4);
   root->left->left->right = new TreeNode(4);
   // TreeNode *res = lowestCommmonAncestor();
   // cout << res->data << endl;
   // cout << endl;
   return 0;
}