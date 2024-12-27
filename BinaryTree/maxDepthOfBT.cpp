//find the height of the tree
#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
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
int maxDepth(TreeNode* root){
    if(!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);    
}
int main() {
    // code here
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(9);
    int res = maxDepth(root);
    cout<<res<<endl;
   
    return 0;
}