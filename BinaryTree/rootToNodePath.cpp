#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data1, TreeNode *left1, TreeNode *right1){
        data = data1;
        left = left1;
        right = right1;
    }
    TreeNode(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};
//code to find the root to path node all if the node is present 
bool isPathAvailable(TreeNode* root,vector<int> &path,vector<vector<int>> &allPath,int x){
    if(!root) return false;

    path.push_back(root->data);
    // if(root->data==x) return true;//this will return the true and will only give one path node

    if(root->left!=nullptr && root->right!=nullptr){
        allPath.push_back(path);
    }else{
        //if root->left is false and root->right is false
        //recursively call that
        isPathAvailable(root->left,path,allPath,x);
        isPathAvailable(root->right,path,allPath,x);
    }
    path.pop_back();
    return false;
}
void recursion(TreeNode* root,vector<int> &path,vector<vector<int>> &allPath){
    if(!root) return;
    path.push_back(root->data);
    if(root->left==nullptr && root->right==nullptr){
        allPath.push_back(path);
    }
    recursion(root->left,path,allPath);
    recursion(root->right,path,allPath);
    path.pop_back();
}
vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
    vector<int> path;
    vector<vector<int>> allPath;
    if(root==nullptr) return allPath;
    // isPathAvailable(root,path,x);
    recursion(root,path,allPath);
    return allPath;
}
int main() {
    // code here
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(9);
    root->left->left  =new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(10);
    vector<vector<int>> res = allRootToLeaf(root);
    for(auto &ele:res){
        for(auto &it:ele){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}