/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
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
class BSTIterator
{
public:
  stack<TreeNode *> st;
  BSTIterator(TreeNode *root)
  {
    pushAll(root);
  }

  bool hasNext()
  {
    return !st.empty();
  }

  int next()
  {
    TreeNode *node = st.top();
    st.pop();
    int data = node->data;
    pushAll(node->right);
    return data;
  }
  private:
  void pushAll(TreeNode* root){
    while(root!=nullptr){
      st.push(root);
      root = root->left;
    }
  }
};

int main()
{
  BSTIterator bSTIterator = new BSTIterator([ 7, 3, 15, null, null, 9, 20 ]);
  bSTIterator.next(); // return 3

  bSTIterator.next(); // return 7

  bSTIterator.hasNext(); // return True

  bSTIterator.next(); // return 9

  bSTIterator.hasNext(); // return True

  bSTIterator.next(); // return 15

  bSTIterator.hasNext(); // return True

  bSTIterator.next(); // return 20

  bSTIterator.hasNext(); // return False
  return 0;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */