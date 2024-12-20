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
void findRightView(TreeNode* root,int level,vector<int> &ans
){
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    findRightView(root->right,level+1,ans);
    findRightView(root->left,level+1,ans);
}
void findLeftView(TreeNode* root,int level, vector<int> &ans){
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    findLeftView(root->left,level+1,ans);
    findLeftView(root->right,level+1,ans);
}
vector<int> leftView(TreeNode* root){
    vector<int> ans;
    int level=0;
    findLeftView(root,level,ans);
    return ans;
}
vector<int> rightView(TreeNode* root){
    //iterative approach TC: O(N) SC: O(2N)
    // queue<pair<TreeNode*,int>> q;
    // vector<int> ans;
    // if(!root) return ans;
    // map<int,int> mpp;
    // q.push({root,0});
    // while(!q.empty()){
    //     auto element = q.front();
    //     q.pop();
    //     //first push left then right
    //     TreeNode* node = element.first;
    //     int level = element.second;
    //     mpp[level] = node->data;
    //     if(node->left) q.push({node->left,level+1});
    //     if(node->right) q.push({node->right,level+1});
    // }
    // for (auto &it : mpp) {
    //     ans.push_back(it.second);
    // }
    // return ans;

    vector<int> ans;
    int level = 0;
    findRightView(root,level,ans);
    return ans;

}
int main() {
    // code here
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> res = leftView(root);
    // vector<int> res = rightView(root);
    for (auto &it : res) {
        cout<<it<<" ";
    }

    return 0;
}