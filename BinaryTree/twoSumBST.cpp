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
      left = left;
      right = right;
   }
};
// the brute force approach is that we traverse the bst
//  and take the inorder and push in array
// and then use that array to solve
// TC: O(n) + O(n)
// SC: O(n)

class Solutions
{
public:
   stack<TreeNode *> st;
   bool isReverse = false;
   Solutions(TreeNode *root, bool isReverse = false)
   {
      this->isReverse = isReverse;
      pushAll(root);
   }
   int next()
   {
      TreeNode *node = st.top();
      st.pop();
      if (isReverse)
      {
         if (node->left != nullptr)
            pushAll(node->left);
      }
      else
      {
         if (node->right != nullptr)
            pushAll(node->right);
      }
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
         isReverse ? root = root->left : root = root->right;
      }
   }
};

class Solution
{
public:
   bool twoSumBST(TreeNode *root, int k)
   {
      // your code goes here
      if (!root)
         return false;
      Solutions *rightPoint = new Solutions(root, true);
      Solutions *leftPoint = new Solutions(root);
      int rightNext = rightPoint->next();
      int leftNext = leftPoint->next();
      while (rightNext > leftNext)
      {
         if (rightNext + leftNext > k)
         {
            rightNext = rightPoint->next();
         }
         else if (rightNext + leftNext < k)
         {
            leftNext = leftPoint->next();
         }
         else
         {
            return true;
         }
      }
      return false;
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