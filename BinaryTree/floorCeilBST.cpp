
//  * Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
   void findCeilBST(TreeNode *root, int key, vector<int> &ans)
   {
      int ceil = -1;
      while (root != nullptr)
      {
         if (root->data == key)
         {
            ceil = root->data;
            break;
         }
         else if (root->data > key)
         {
            ceil = root->data;
            root = root->left;
         }
         else
         {
            root = root->right;
         }
      }
      ans.push_back(ceil);
   }
   void findFloorBST(TreeNode *root, int key, vector<int> &ans)
   {
      int floor = -1;
      while (root != nullptr)
      {
         if (root->data == key)
         {
            floor = root->data;
            break;
         }
         else if (root->data > key)
         {
            root = root->left;
         }
         else
         {
            floor = root->data;
            // now found go for bigger value
            root = root->right;
         }
      }
      ans.push_back(floor);
   }
   vector<int> floorCeilOfBST(TreeNode *root, int key)
   {
      // your code goes here
      vector<int> ans;
      findFloorBST(root, key, ans);
      findCeilBST(root, key, ans);
      return ans;
   }
};
//

TreeNode *insert(TreeNode *node, int key)
{
   if (node == nullptr)
      return new TreeNode(key);
   if (key < node->data)
      node->left = insert(node->left, key);
   else if (key > node->data)
      node->right = insert(node->right, key);
   return node;
}
int main()
{
   // code here
   // Create the BST
   TreeNode *root = nullptr;
   root = insert(root, 8);
   insert(root, 4);
   insert(root, 12);
   insert(root, 2);
   insert(root, 6);
   insert(root, 10);
   insert(root, 14);

   // Key value to find floor and ceil for
   int key = 11;

   // Solution instance
   Solution sol;
   vector<int> result = sol.floorCeilOfBST(root, key);

   // Output the floor and ceil values
   cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

   return 0;
}