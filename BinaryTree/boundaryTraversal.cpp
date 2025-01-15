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
bool isLeaf(TreeNode *root)
{
   if (root->left == nullptr && root->right == nullptr)
      return true;
   else
      return false;
}
void addLeftBoundary(TreeNode *root, vector<int> &res)
{
   // start from the left
   TreeNode *curr = root->left;
   while (curr)
   {
      if (!isLeaf(root))
         res.push_back(curr->data);
      if (curr->left)
         curr = curr->left;
      else
         curr = curr->right;
   }
}
void addLeavesNodes(TreeNode *root, vector<int> &res)
{
   // use preorder traversal root left right
   if (isLeaf(root))
      res.push_back(root->data);
   // move as left as possible
   if (root->left)
   {
      addLeavesNodes(root->left, res);
   }
   else
   {
      addLeavesNodes(root->right, res);
   }
}
void addRightBoundary(TreeNode *root, vector<int> &res)
{
   // make temp array add the value and then store in res in reverse order
   vector<int> temp;
   TreeNode *curr = root->right;
   while (curr)
   {
      if (!isLeaf(root))
         temp.push_back(curr->data);
      if (curr->right)
         curr = curr->right;
      else
         curr = curr->left;
   }
}
vector<int> boundary(TreeNode *root)
{
   // first push the first root node in ans
   vector<int> res;
   if (root == NULL)
      return res;
   if (!isLeaf(root))
      res.push_back(root->data);
   addLeftBoundary(root, res);
   addLeavesNodes(root, res);
   addRightBoundary(root, res);
   return res;
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
   vector<int> res = boundary(root);
   for (int i = 0; i < res.size(); i++)
   {
      cout << res[i] << " " << endl;
   }

   return 0;
}