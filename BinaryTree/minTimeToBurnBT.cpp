#include <bits/stdc++.h>
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
void parentMapAndFindNode(TreeNode* root,int start,TreeNode* &nodeToBurn,unordered_map<TreeNode*,TreeNode*> &parentMap){
   //do level order traversal
   queue<TreeNode *> que;
   que.push(root);
   while(!que.empty()){
      int size = que.size();
         TreeNode *node = que.front();
         que.pop();
         if(node->data==start)
            nodeToBurn = node;
         if(node->left){
            que.push(node->left);
            parentMap[node->left] = node;
         }
         if(node->right){
            que.push(node->right);
            parentMap[node->right] = node;
         }
   }
   
}
int burnTreeNode(TreeNode* root,TreeNode* nodeToBurn,unordered_map<TreeNode*,TreeNode*> &parentMap){
   unordered_map<TreeNode *, int> visitedMap;
   queue<TreeNode *> que;
   int burnTime = 0;
   que.push(nodeToBurn);
   visitedMap[nodeToBurn] = 1;
   while(!que.empty()){
      int size = que.size();
      bool isAnyNodeBurned= false;
      for (int i = 0; i < size;i++){
         TreeNode *node = que.front();
         que.pop();
         vector<TreeNode *> neighbors = {node->left, node->right, parentMap[node]};
         for(auto &neighbor:neighbors){
            if(neighbor && !visitedMap[neighbor]){
               visitedMap[neighbor] = 1;
               que.push(neighbor);
               isAnyNodeBurned = true;
            }
         }
      }
      if(isAnyNodeBurned)
         burnTime++;
   }
   return burnTime;
}
int timeToBurnTree(TreeNode* root,int start){
   if(!root)
      return 0;
   //find the node to burn
   unordered_map<TreeNode *, TreeNode *> parentMap;
   TreeNode *nodeToBurn = nullptr;
   parentMapAndFindNode(root, start,nodeToBurn,parentMap);
   if(!nodeToBurn)
      return 0;
   int burnTime = burnTreeNode(root, nodeToBurn, parentMap);
   return burnTime;
}
int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);
   int res = timeToBurnTree(root, 5);
   cout << "time to burn:" << res << endl;

   return 0;
}
