#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int data;
   TreeNode *right;
   TreeNode *left;
   TreeNode(int data, TreeNode *left = nullptr, TreeNode *right = nullptr)
   {
      this->data = data;
      this->left = left;
      this->right = right;
   }
};
class Solutions
{
public:
   stack<TreeNode *> st;

   Solutions(TreeNode *root)
   {
      pushAll(root);
   }
   int next()
   {
      TreeNode *node = st.top();
      st.pop();
      if (node->right != nullptr)
         pushAll(node->right);
      return node->data;
   }
   bool hasNext()
   {
      return !st.empty();
   }

private:
   void pushAll(TreeNode *root)
   {
      while (root != nullptr)
      {
         st.push(root);
         root = root->left;
      }
   }
};

int main()
{
   // code here
   TreeNode *root = new TreeNode(7);
   root->left = new TreeNode(3);
   root->right = new TreeNode(15);
   root->right->left = new TreeNode(9);
   root->right->right = new TreeNode(20);
   Solutions *sol = new Solutions(root);
   sol->next();
   sol->hasNext();
   sol->next();
   sol->next();
   sol->hasNext();
   return 0;
}