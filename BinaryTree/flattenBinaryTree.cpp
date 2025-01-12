#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int value;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
// TreeNode *prevNode = nullptr;
// void flatten(TreeNode *root)
// {
//    if (root == nullptr)
//       return;
//    flatten(root->right);
//    flatten(root->left);
//    root->right = prevNode;
//    root->left = nullptr;
//    prevNode = root;
// }

// flatten using linked list and morris traversal
// void flatten(TreeNode *root)
// {
//    // follow the inorder traversal morris traversal //TC: O(2N) SC: O(1)
//    TreeNode *curr = root;
//    while (curr != nullptr)
//    {
//       if (curr->left != nullptr)
//       {
//          // make a prevnode
//          TreeNode *prevNode = curr->left;
//          while (prevNode->right != nullptr)
//             prevNode = prevNode->right;
//          // then point it
//          prevNode->right = curr->right;
//          curr->right = curr->left;
//          curr = curr->right;
//       }
//       curr = curr->right;
//    }
// }

// flatten linked list using stack
void flatten(TreeNode *root)
{
   if (root == nullptr)
      return;
   stack<TreeNode *> st;
   st.push(root);
   while (!st.empty())
   {
      auto node = st.top();
      st.pop();
      if (node->right != nullptr)
         st.push(node->right);
      if (node->left)
         st.push(node->left);
      if (!st.empty())
      {
         node->right = st.top();
      }
      node->left = nullptr;
   }
}
void printLinkedList(TreeNode *root)
{
   TreeNode *current = root;
   while (current != nullptr)
   {
      cout << current->value << " ";
      current = current->right;
   }
   cout << endl;
}

int main()
{
   // Creating a binary tree
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);
   flatten(root);

   // Print the linked list
   printLinkedList(root);

   // Now you can pass 'root' to any function that requires a binary tree

   return 0;
}
