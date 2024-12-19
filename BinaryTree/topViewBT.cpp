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
vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int level = it.second;
        TreeNode* current = it.first;
        if(mp.find(level)==mp.end()) mp[level] = current->data;
        if(current->left){
            q.push({current->left,level-1});
        }
        if(current->right){
            q.push({current->right,level+1});
        }

    }
    for(auto &it:mp){
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
     int n;
     cin>>n;
     vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode* root = nullptr;
    createTree(root,arr);
    vector<int> ans = topView(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }

    cout<<endl;
    return 0;
}
        