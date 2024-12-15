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

void postOrderFun(TreeNode *root, vector<int> &ans)
{
   if (root == nullptr)
      return;
   // LRN
   postOrderFun(root->left, ans);
   postOrderFun(root->right, ans);
   ans.push_back(root->data);
}
vector<int> postorder(TreeNode *root)
{
   // vector<int> ans;
   // postOrderFun(root, ans);
   // return ans;
   // postorder traversal using two stack
   // TC: O(3N) SC: O(2N)
   vector<int> ans;
   stack<TreeNode *> st1, st2;
   if (root == NULL)
      return ans;
   st1.push(root);
   while (!st1.empty())
   {
      TreeNode *it = st1.top();
      st1.pop();
      st2.push(it);
      if (it->left != nullptr)
      {
         st1.push(it->left);
      }
      if (it->right != nullptr)
         st1.push(it->right);
   }
   while (!st2.empty())
   {
      auto node = st2.top();
      st2.pop();
      ans.push_back(node->data);
   }
   return ans;
}
vector<int> postorder2(TreeNode *root)
{
   vector<int> ans;
   stack<TreeNode *> st;
   if (root == nullptr)
      return ans;
   TreeNode *curr = root;
   while (curr != NULL || !st.empty())
   {
      /* code */
      if (curr != nullptr)
      {
         st.push(curr);
         curr = curr->left;
      }
      else
      {
         TreeNode *temp = st.top()->right;
         if (temp == nullptr)
         {
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            while (!st.empty() && temp == st.top()->right)
            {
               temp = st.top();
               st.pop();
               ans.push_back(temp->data);
            }
         }
         else
         {
            curr = temp;
         }
      }
   }

   return ans;
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
   vector<int> res = postorder2(root);
   for (auto &ele : res)
   {
      cout << ele << " ";
   }

   return 0;
}