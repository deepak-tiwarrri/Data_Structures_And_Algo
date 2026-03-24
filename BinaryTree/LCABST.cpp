class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;
};
class Solution
{
public:
   TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
   {
      if (root == nullptr)
         return nullptr;
      int curr = root->data;
      if (curr < p->data && curr < q->data)
      {
         lowestCommonAncestor(root->left, p, q);
      }
      if (curr > p->data && curr > q->data)
      {
         lowestCommonAncestor(root->right, p, q);
      }
      return root;
   }
};