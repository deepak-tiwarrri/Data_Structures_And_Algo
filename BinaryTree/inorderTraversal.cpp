#include <bits/stdc++.h>
using namespace std;

class TreeNode{
   public:
      int data;
      TreeNode *left;
      TreeNode *right;
   TreeNode(int data1,TreeNode*left,TreeNode*right){
      data = data1;
      left = left;
      right = right;
   }
   TreeNode(int data1){
      data = data1;
      left = nullptr;
      right = nullptr;
   }
};

vector<int> inorderTraversal(TreeNode *root)
{
   // iterative approach
   // LNR //left root and right
   stack<TreeNode *> st;
   vector<int> ans;
   TreeNode *node = root;
   if(root==nullptr)
      return ans;
   while(!st.empty() || node !=nullptr){
      while(node!=nullptr){
         st.push(node);
         node = node->left;
      }
      //if node is null push the data and move to right
      //pop the stack and push that element
      node = st.top();
      st.pop();
      ans.push_back(node->data);
      node = node->right;
   }
   return ans;
}
void inOrderFun(TreeNode *root, vector<int> &ans)
{
   // LNR
   if (root == nullptr)
      return;
   inOrderFun(root->left, ans);
   ans.push_back(root->data);
   inOrderFun(root->right, ans);
}

void inOrderTraversalRecursion(TreeNode* root, vector<int> &ans){
   if(root==nullptr)
      return;
   inOrderTraversalRecursion(root->left, ans);
   ans.push_back(root->data);
   inOrderTraversalRecursion(root->right, ans);
}

int main()
{
   // code here
   TreeNode *root = new TreeNode(1);
   vector<int> ans;
   root->left = new TreeNode(6);
   root->right = new TreeNode(15);
   root->left->right = new TreeNode(10);
   root->left->left = new TreeNode(5);
   // inOrderTraversalRecursion(root,ans);
   vector<int> result = inorderTraversal(root);
   for (auto &it : result)
      cout << it << " ";

   //1
//6     9

//5  10
   return 0;
}