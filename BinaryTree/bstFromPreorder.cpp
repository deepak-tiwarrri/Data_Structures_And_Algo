#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode *bstFromPreorder(vector<int> &nums)
{
  int i = 0;
  return buildBST(nums, i, INT_MAX);
}
TreeNode *buildBST(vector<int> &nums, int &i, int bound)
{
  if (i == nums.size() || nums[i] > bound)
    return NULL;
  TreeNode *root = new TreeNode(nums[i++]);
  root->left = buildBST(nums, i, root->data);
  root->right = buildBST(nums, i, bound);
  return root;
}
void printInOrder(TreeNode *root)
{
  if (!root)
    return;
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
int main()
{
  vector<int> nums = {8, 5, 1, 7, 10, 12};
  TreeNode *root = bstFromPreorder(nums);
  printInOrder(root);
  return 0;
}