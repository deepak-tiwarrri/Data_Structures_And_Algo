#include<bits/stdc++.h>
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
vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    queue<pair<TreeNode*,int>> q;
    map<int,int> mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int level = it.second;
        mpp[level] = node->data;
        if(node->left){
            q.push({node->left,level-1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
    }
    for(auto &it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
void createTree(TreeNode* root,vector<int> &arr){
    if(arr.empty()) return;
    queue<TreeNode*> q;
    q.push(root);
    int i=0;
    while(i<arr.size() && !q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if(i<arr.size()){
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
            i++;
        }
        if(i<arr.size()){
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
            i++;
        }
    }
}
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(60);
    root->left->left = new TreeNode(40);
    vector<int> ans = bottomView(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }

    cout<<endl;
    return 0;
}
        