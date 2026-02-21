/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
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
class Solution
{
public:
   TreeNode *insertIntoBST(TreeNode *root, int val)
   {
      // your code goes here
      if (root == nullptr)
         return new TreeNode(val);
      TreeNode *curr = root;
      while (true)
      {
         if (curr->data > val)
         {
            // move left
            if (curr->left != nullptr)
               curr = curr->left;
            else
            {
               curr->left = new TreeNode(val);
               // directly break and return the root no need to do further insertion
               break;
            }
         }
         else
         {
            // move right
            // and if it is lesser than equal to
            if (curr->right != nullptr)
               curr = curr->right;
            else
            {
               curr->right = new TreeNode(val);
               break;
            }
         }
      }
      return root;
   }
};
void printInOrder(TreeNode *root)
{
   if (root == nullptr)
      return;
   printInOrder(root->left);
   cout << root->data << " ";
   printInOrder(root->right);
}
int main()
{
   // code here
   TreeNode *root = new TreeNode(4);
   root->left = new TreeNode(2);
   root->right = new TreeNode(7);
   root->left->left = new TreeNode(1);
   root->left->right = new TreeNode(3);
   Solution sol;
   TreeNode *res = sol.insertIntoBST(root, 10);
   printInOrder(res);
   return 0;
}