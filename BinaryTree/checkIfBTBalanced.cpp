#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBalanced(TreeNode* root){
    if(!root) return 0;
    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);
    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}

int main() {
    // code here
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(9);
    root->right->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    bool isbalanced = isBalanced(root);
    if(isbalanced) cout<<"true"<<endl;
    else cout<<"false"<<endl;   

    return 0;
}