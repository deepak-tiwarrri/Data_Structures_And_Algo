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
vector<vector<int>> levelOrder(TreeNode *root)
{
   // queue<TreeNode *> q;
   // vector<vector<int>> ans;
   // if (root == nullptr)
   //    return ans;
   // q.push(root);
   // while (!q.empty())
   // {
   //    int queueSize = q.size();
   //    vector<int> level;
   //    for (int i = 0; i < queueSize; i++)
   //    {
   //       TreeNode *current = q.front();
   //       q.pop();
   //       if (current->left != nullptr)
   //          q.push(current->left);
   //       if (current->right != nullptr)
   //          q.push(current->right);
   //       level.push_back(current->data);
   //    }
   //    ans.push_back(level);
   // }
   // return ans;
   vector<vector<int>> ans;
   queue<TreeNode *> q;
   if(root==nullptr)
      return ans;
   q.push(root);
   while(!q.empty()){
      int size = q.size();
      vector<int> level;
      for (int i = 0; i < size;i++){
         TreeNode *node = q.front();
         q.pop();
         if(node->left)
            q.push(node->left);
         if(node->right)
            q.push(node->right);
         level.push_back(node->data);
      }
      ans.push_back(level);
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
   vector<vector<int>> res = levelOrder(root);
   for (auto &ele : res)
   {
      for (auto &it : ele)
         cout << it << " ";
      cout << endl;
   }

   return 0;
}