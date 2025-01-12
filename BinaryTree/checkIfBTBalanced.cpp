#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int findHeight(TreeNode* root){
     if(!root) return 0;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root){
   return findHeight(root)!=-1;
}

int main() {
    // code here
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    bool isbalanced = isBalanced(root);
    if(isbalanced) cout<<"true"<<endl;
    else cout<<"false"<<endl;   

    return 0;
}