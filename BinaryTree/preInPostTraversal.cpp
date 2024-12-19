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
vector<vector<int>> preInPostTraversal(TreeNode *root)
{
   // pseudo code will be easy
   // preorder
   // if st.second==1
   // take it and put the data into preorder
   // reinsert it with {node,2}
   // check if it has left then move to left means put that value into the stack with {node,1}
   // inorder
   // if st.second ==2
   // take it and put the data into inorder
   // reinsert it with {node,3}
   // check if it has right then move to right means put that value into the stack with {node,1}
   // postorder
   // take it pop it and take the value into the postorder

   vector<vector<int>> ans;
   vector<int> preorder;
   vector<int> inorder;
   vector<int> postorder;

   if (root == nullptr)
      return ans;
   stack<pair<TreeNode *, int>> st;
   st.push({root, 1});
   while (!st.empty())
   {
      auto [node, state] = st.top();
      st.pop();
      if (state == 1)
      {
         preorder.push_back(node->data);
         state++;
         st.push({node, state});
         if (node->left != nullptr)
         {
            st.push({node->left, 1});
         }
      }
      else if (state == 2)
      {
         inorder.push_back(node->data);
         state++;
         st.push({node, state});
         if (node->right != nullptr)
         {
            st.push({node->right, 1});
         }
      }
      else
      {
         postorder.push_back(node->data);
      }
   }
   return {preorder, inorder, postorder};
}

int main()
{
   // code here
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->left->right = new TreeNode(7);
   root->right->left->right->right = new TreeNode(8);
   vector<vector<int>> res = preInPostTraversal(root);
   for (auto &it : res)
   {
      for (auto &ele : it)
      {
         cout << ele << " ";
      }
      cout << endl;
   }

   return 0;
}