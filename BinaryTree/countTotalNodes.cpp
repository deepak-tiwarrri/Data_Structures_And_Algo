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
vector<int> morrisTraversal(TreeNode *root)
{
   // morris traversal didn't take any space
   vector<int> ans;
   if (root == nullptr)
      return ans;
   TreeNode *curr = root;
   while (curr != nullptr)
   {
      if (curr->left == nullptr)
      {
         // then push back and
         ans.push_back(curr->data);
         curr = curr->right;
      }
      else
      {
         // take the left and point the thread
         TreeNode *prevNode = curr->left;
         while (prevNode->right != nullptr && prevNode->right != curr)
         {
            prevNode = prevNode->right;
         }
         // if prevNode->right == nullptr
         if (prevNode->right == nullptr)
         {
            prevNode->right = curr;
            curr = curr->left;
         }
         else
         {
            prevNode->right = nullptr;
            ans.push_back(curr->data);
            curr = curr->right;
         }
      }
   }
   return ans;
}
int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);
   
   return 0;
}
