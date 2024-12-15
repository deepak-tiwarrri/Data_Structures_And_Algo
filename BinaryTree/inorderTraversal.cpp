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

vector<int> inorderTraversal(TreeNode *root)
{
   // iterative approach
   // LNR //left root and right
   stack<TreeNode *> st;
   vector<int> ans;
   if (root == nullptr)
      return ans;
   TreeNode *node = root;
   while (true)
   {
      if (node != nullptr)
      {
         // if node is not null
         st.push(node);
         node = node->left;
      }
      else
      {
         // if node is nullptr
         if (st.empty())
            break;
         node = st.top();
         st.pop();
         ans.push_back(node->data);
         node = node->right;
      }
   }
   return ans;
}
void inOrderFun(TreeNode *root, vector<int> &ans)
{
   // LNR
   if (root == nullptr)
      return;
   inOrderFun(root->left, ans);
   ans.push_back(root->data);
   inOrderFun(root->right, ans);
}
// vector<int> inorder(TreeNode *root)
// {
//    vector<int> ans;
//    inOrderFun(root, ans);
//    return ans;
// }

int main()
{
   // code here
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(6);
   root->right = new TreeNode(9);
   root->left->right = new TreeNode(10);
   root->left->left = new TreeNode(5);
   vector<int> res = inorderTraversal(root);
   for (auto &it : res)
      cout << it << " ";

   return 0;
}