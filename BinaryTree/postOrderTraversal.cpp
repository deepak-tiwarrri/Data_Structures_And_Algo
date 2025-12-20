#include<bits/stdc++.h>
using namespace std;
class TreeNode{
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  TreeNode(int data,TreeNode* left=nullptr,TreeNode* right=nullptr) : data(data), left(left), right(right) {}
};

vector<int> postOrderTraversalIterative(TreeNode* root){
  vector<int> ans;
  if(root==nullptr)
    return ans;
  stack<TreeNode *> st1, st2;
  st1.push(root);
  while (!st1.empty())
  {
    TreeNode *node = st1.top();
    st1.pop();
    st2.push(node);
    if(node->left)
      st1.push(node->left);
    if(node->right)
      st1.push(node->right);
  }
  while(!st2.empty()){
    ans.push_back(st2.top()->data);
    st2.pop();
  }
  return ans;
}
int main(){

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->left->right = new TreeNode(7);
  root->right->left->right->right = new TreeNode(8);

  vector<int> result = postOrderTraversalIterative(root);
  for(auto &it:result){
    cout << it << " ";
  }
  cout << endl;

  return 0;
}