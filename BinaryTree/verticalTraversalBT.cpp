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
vector<vector<int>> verticalTraversal(TreeNode* root) {
    //vertical,level,node
   map<int,map<int,multiset<int>>> mp;
   queue<pair<TreeNode*,pair<int,int>>> q;
   q.push({root,{0,0}});
   while(!q.empty()){
       auto it = q.front();
       q.pop();
       TreeNode* current = it.first;
       int vertical = it.second.first;
       int level = it.second.second;
       mp[vertical][level].insert(current->data);
       if(current->left){
        q.push({current->left,{vertical-1,level+1}});
       }
       if(current->right){
        q.push({current->right,{vertical+1,level+1}});
       }
   }
   vector<vector<int>> ans;
   for(auto p:mp){
    vector<int> col;
    for(auto q:p.second){
        col.insert(col.end(),q.second.begin(),q.second.end());
    }
    ans.push_back(col);
   }

    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(9);
    root->right->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    vector<vector<int>> ans = verticalTraversal(root);
    for(auto &it:ans){
        for(auto &ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}