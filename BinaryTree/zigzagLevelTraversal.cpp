#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int data, TreeNode *left, TreeNode *right)
   {
      this->data = data;
      this->left = left;
      this->right = right;
   }
   TreeNode(int data)
   {
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
   }
};
vector<vector<int>> zigZagLevelTraversal(TreeNode *root)
{
   vector<vector<int>> ans;
   if (root == nullptr)
      return ans;
   queue<TreeNode *> queue;
   queue.push(root);
   int leftToRight = 0;
   while (!queue.empty())
   {
      int size = queue.size();
      vector<int> result;
      for (int i = 0; i < size; i++)
      {
         TreeNode *node = queue.front();
         queue.pop();
         if (node->left)
            queue.push(node->left);
         if (node->right)
         {
            queue.push(node->right);
         }
         result.push_back(node->data);
      }
      if (leftToRight == 0)
      {
         ans.push_back(result);
      }
      else
      {
         reverse(result.begin(), result.end());
         ans.push_back(result);
      }
      leftToRight = 1 - leftToRight;
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
   root->left->right = new TreeNode(9);
   root->right->left = new TreeNode(9);
   root->right->left->right = new TreeNode(10);
   root->left->left->right = new TreeNode(5);
   root->left->left->right->right = new TreeNode(6);
   vector<vector<int>> result = zigZagLevelTraversal(root);
   for (auto &it : result)
   {
      for (auto &ele : it)
      {
         cout << ele << " ";
      }
      cout << endl;
   }
   cout << endl;
   return 0;
}