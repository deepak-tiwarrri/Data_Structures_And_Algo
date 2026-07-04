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
class Solution
{
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    if (inorder.size() != postorder.size())
      return NULL;
    map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
      mpp[inorder[i]] = i;
    }
    return buildBTPostAndIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
  }

private:
  TreeNode *buildBTPostAndIn(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &mpp)
  {
    if (inStart > inEnd || postStart > postEnd)
      return NULL;
    // now make root
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int inRoot = mpp[postorder[postEnd]];
    int numsLeft = inRoot - inStart;
    root->left = buildBTPostAndIn(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, mpp);
    root->right = buildBTPostAndIn(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, mpp);
    return root;
  }
};
void inOrderFun(TreeNode *root, vector<int> &ans)
{
  // LNR
  if (root == nullptr)
    return;
  inOrderFun(root->left, ans);
  ans.push_back(root->data);
  inOrderFun(root->right, ans);
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> inOrder, postOrder;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    inOrder.push_back(x);
  }
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    postOrder.push_back(x);
  }
  Solution sol;
  TreeNode *result = sol.buildTree(inOrder, postOrder);
  vector<int> ans;
  inOrderFun(result, ans);
  for (auto &it : ans)
  {
    cout << it << " ";
  }

  return 0;
}