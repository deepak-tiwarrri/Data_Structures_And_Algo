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
bool isLeafNode(TreeNode *root)
{
   return root->right == NULL && root->left == NULL ? true : false;
}
void addLeavesBoundary(vector<int> &res, TreeNode *root)
{
   auto currNode = root;
   if (currNode->left)
      addLeavesBoundary(res, currNode->left);
   if (isLeafNode(currNode))
   {
      res.push_back(currNode->data);
      return;
   }
   else
      addLeavesBoundary(res, currNode->right);
}
void addLeftBoundary(vector<int> &res, TreeNode *root)
{
   TreeNode *currNode = root;
   while (currNode)
   {
      if (!isLeafNode(currNode))
         res.push_back(currNode->data);
      if (currNode->left)
         currNode = currNode->left;
      else
         // addLeftBoundary(res,currNode->right)
         currNode = currNode->right;
   }
}
void addRightBoundary(vector<int> &res, TreeNode *root)
{
   TreeNode *currNode = root;
   vector<int> temp;
   while (currNode)
   {
      if (!isLeafNode(currNode))
         temp.push_back(currNode->data);
      if (currNode->right)
         currNode = currNode->right;

      else
         currNode = currNode->left;
   }
   for (int i = temp.size() - 1; i >= 0; i--)
   {
      res.push_back(temp[i]);
   }
}
vector<int> boundary(TreeNode *root)
{
   vector<int> res;
   if (root == NULL)
      return res;
   if (!isLeafNode(root))
      res.push_back(root->data);
   addLeftBoundary(res, root->left);
   addLeavesBoundary(res, root);
   addRightBoundary(res, root->right);
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
   for (auto &ele : res)
   {
      cout << ele << " ";
   }

   return 0;
}