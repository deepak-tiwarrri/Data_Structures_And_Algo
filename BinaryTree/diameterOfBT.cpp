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
int findHeight(TreeNode *root, int &diameter)
{
   if (root == nullptr)
      return 0;
   int lh = findHeight(root->left, diameter);
   int rh = findHeight(root->right, diameter);
   diameter = max(diameter, lh + rh);
   return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
   int diameter = 0;
   findHeight(root, diameter);
   return diameter;
}
TreeNode* createTree(const vector<int>& nodes, int index = 0) {
    if (index < nodes.size() && nodes[index] != -1) {
        TreeNode* root = new TreeNode(nodes[index]);
        root->left = createTree(nodes, 2 * index + 1);
        root->right = createTree(nodes, 2 * index + 2);
        return root;
    }
    return nullptr;
}
int main()
{
   // code here
   int n;
   cin>>n;
   vector<int> nums(n);
   for(int i=0;i<n;i++){
      cin>>nums[i];
   }
   TreeNode* root = createTree(nums,0);
   int res = diameterOfBinaryTree(root);
   cout << res << endl;
   return 0;
}