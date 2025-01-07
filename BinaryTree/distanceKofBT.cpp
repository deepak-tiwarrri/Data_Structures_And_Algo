#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
void mapParent(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> parentTrack)
{
   queue<TreeNode*> q;
   q.push(root);
   while (!q.empty())
   {
      /* code */
      auto current = q.front();
      q.pop();
      if(current->left){
         q.push(current->left);
         parentTrack[current->left] = current;
      }
      if(current->right){
         q.push(current->right);
         parentTrack[current->right] = current;
      }
   }
   
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
   unordered_map<TreeNode *, TreeNode *> parentTrack;
      vector<int> ans;
   if(!root) return ans;
   mapParent(root, target, parentTrack);

   // make a visited node
   unordered_map<TreeNode *, bool> visited;
   queue<TreeNode *> q;
   q.push(target);
   int level = 0;
   visited[target] = true;
   while (!q.empty())
   {
      // first get the size
      int size = q.size();

      if (level == k)
         break; // that means which reached till that level and break the loop
      for (int i = 0; i < size; i++)
      {
         auto current = q.front();
         q.pop();

         // node should not be in visited and it should be present first
         if (!visited[current->left] && current->right)
         {
            // then mark it visited
            visited[current->left] = true;
            // add in queue
            q.push(current->left);
         }
         if (!visited[current->right] && current->right)
         {
            visited[current->right] = true;
            q.push(current->right);
         }
         if (!visited[parentTrack[current]] && parentTrack.find(parentTrack[current]) != parentTrack.end())
         {
            visited[parentTrack[current]] = true;
            q.push(parentTrack[current]);
         }
      }
      level++;
   }
   while (!q.empty())
   {
      auto current = q.front();
      q.pop();
      ans.push_back(current->data);
   }
   return ans;
}

TreeNode *buildTree(const vector<int> &nums)
{
   if (nums.empty())
      return nullptr;
   TreeNode *root = new TreeNode(nums[0]);
   queue<TreeNode *> q;
   q.push(root);
   int i = 1;
   while (!q.empty() && i < nums.size())
   {
      TreeNode *current = q.front();
      q.pop();
      if (i < nums.size() && nums[i] != -1)
      {
         current->left = new TreeNode(nums[i]);
         q.push(current->left);
      }
      i++;
      if (i < nums.size() && nums[i] != -1)
      {
         current->right = new TreeNode(nums[i]);
         q.push(current->right);
      }
      i++;
   }
   return root;
}

int main()
{
   int n;
   cin >> n;
   vector<int> nums(n);
   for (int i = 0; i < n; i++)
   {
      cin >> nums[i];
   }
   TreeNode *root = buildTree(nums);

   int targetValue, k;
   cout << "Enter target node value: ";
   cin >> targetValue;
   cout << "Enter distance k: ";
   cin >> k;

   // Find the target node
   queue<TreeNode *> q;
   q.push(root);
   TreeNode *target = nullptr;
   while (!q.empty())
   {
      TreeNode *current = q.front();
      q.pop();
      if (current->data == targetValue)
      {
         target = current;
         break;
      }
      if (current->left)
         q.push(current->left);
      if (current->right)
         q.push(current->right);
   }

   if (target)
   {
      vector<int> result = distanceK(root, target, k);
      cout << "Nodes at distance " << k << " from target " << targetValue << ": ";
      for (int val : result)
      {
         cout << val << " ";
      }
      cout << endl;
   }
  

   return 0;
}