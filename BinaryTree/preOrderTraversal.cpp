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
// void preOrderFun(TreeNode *node, vector<int> &ans)
// {
//    if (node == NULL)
//       return;
//    ans.push_back(node->data);
//    preOrderFun(node->left, ans);
//    preOrderFun(node->right, ans);
// }
// vector<int> preorder(TreeNode *root)
// {
//    vector<int> ans;
//    preOrderFun(root, ans);
//    return ans;
// }
void preOrderFun(TreeNode *node, vector<int> &ans)
{
   if (node == NULL)
      return;
   ans.push_back(node->data);
   preOrderFun(node->left, ans);
   preOrderFun(node->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
   vector<int> ans;
   if (root == nullptr)
      return ans;
   // preOrderFun(root, ans);
   stack<TreeNode *> st;
   st.push(root);
   while (!st.empty())
   {
      TreeNode *current = st.top();
      st.pop();
      ans.push_back(current->data);
      if (current->right != NULL)
         st.push(current->right);
      if (current->left != NULL)
         st.push(current->left);
   }
   return ans;
}

int main()
{
   // code here
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(6);
   root->right = new TreeNode(9);
   root->left->right = new TreeNode(10);
   root->left->left = new TreeNode(5);
   vector<int> res = preorderTraversal(root);
   for (auto &it : res)
      cout << it << " ";

   return 0;
}