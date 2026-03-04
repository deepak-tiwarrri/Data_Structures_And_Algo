
#include <bits/stdc++.h>
using namespace std;
/*
  kthSmallestAndLargestBST.cpp -- Comments and test cases only (no code changes)

  Goal:
  - Describe approaches to find the k-th smallest and k-th largest element in a
    Binary Search Tree (BST).
  - Provide example tree diagrams and at least two sample inputs + expected outputs.

  Approaches (high-level, no code):
  1) In-order traversal (left, node, right) yields nodes in ascending order.
     - Visit nodes in-order and count visits; when count == k, the current node's
       value is the k-th smallest.
  2) Reverse in-order traversal (right, node, left) yields nodes in descending order.
     - Visit nodes in reverse in-order and count visits; when count == k, the
       current node's value is the k-th largest.
  3) Alternative using counts:
     - Compute total number of nodes n. The k-th largest is the (n - k + 1)-th
       smallest. This lets you reuse an in-order kth-smallest implementation.
  4) Edge cases:
     - If k < 1 or k > n, report "k out of range" (or return a sentinel value like -1
       depending on your API contract).
     - BST may contain duplicates; decide whether duplicates count as separate
       elements (typical traversal-based approaches do count duplicates separately).

  Return / API notes (suggestion for your implementation):
  - `int kthSmallest(TreeNode* root, int k)` should return the value of the k-th
    smallest node (or a sentinel if out-of-range).
  - `int kthLargest(TreeNode* root, int k)` should return the value of the k-th
    largest node (or a sentinel if out-of-range).

  Example BST (primary example used below):

           20
          /  \
         8    22
        / \
       4  12
          / \
         10 14

  In-order (ascending): 4, 8, 10, 12, 14, 20, 22  (n = 7)
  Reverse in-order (descending): 22, 20, 14, 12, 10, 8, 4

  Sample 1
  --------
  Input description (use any convenient input format in your test harness):
    - Insert nodes in order: 20 8 22 4 12 10 14
    - k = 3
  Expected output:
    - kth smallest (k=3): 10
    - kth largest  (k=3): 12

  Sample 2
  --------
  Input:
    - Same tree as above
    - k = 1
  Expected output:
    - kth smallest (k=1): 4
    - kth largest  (k=1): 22

  Sample 3 (alternate tree)
  -------------------------
  Tree:

           15
          /  \
         6    18
        / \     \
       3   7     20

  In-order: 3, 6, 7, 15, 18, 20  (n = 6)
  Input: insert order 15 6 18 3 7 20, k = 4
  Expected output:
    - kth smallest (k=4): 15
    - kth largest  (k=4): 7

  Suggested stdin format you can adopt (simple and easy to parse):
    Line 1: n   (number of nodes)
    Line 2: n space-separated integers (insertion order into BST)
    Line 3: k

  Example stdin for Sample 1:
    7
    20 8 22 4 12 10 14
    3

  Expected console output for that stdin (two lines):
    kth smallest: 10
    kth largest: 12

  Notes / Hints for your implementation (no code):
  - If you implement recursive traversal, carry the counter by reference or
    use a helper that returns an optional/result when the k-th element is found
    to early-stop further recursion.
  - Iterative in-order (using a stack) is also simple and avoids recursion depth
    issues for deep trees.
  - When reusing the same traversal for both queries, you may compute both values
    in a single pass if you traverse to generate a sorted list of values (O(n)
    extra memory). For O(1) extra memory, perform two separate traversals or
    transform k to (n - k + 1) and reuse the k-th smallest routine.

  If you'd like, I can also add a small README-style comment describing how
  to run tests using the existing `main()` skeleton in this file.
*/
// Definition for a binary tree node.
class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data, TreeNode *left = NULL, TreeNode *right = NULL)
  {
    this->left = left;
    this->right = right;
    this->data = data;
  }
};
class Solution
{
public:
  int kthSmallest(TreeNode *root, int k)
  {
    int result = -1;
    inorderTraversal(root, k, result);
    return result;
  }

  int kthLargest(TreeNode *root, int k)
  {
    int result = -1;
    reverseInorderTraversal(root, k, result);
    return result;
  }
  vector<int> kLargesSmall(TreeNode *root, int k)
  {
    // your code goes here
    return {kthSmallest(root, k), kthLargest(root, k)};
  }

private:
  // helper returns true when the k-th element has been found; this
  // allows us to stop recursion early.
  bool inorderTraversal(TreeNode *root, int &k, int &result)
  {
    if (!root)
      return false;
    // traverse left subtree
    if (inorderTraversal(root->left, k, result))
      return true; // found in left side, bubble up

    // visit current node
    if (--k == 0)
    {
      result = root->data;
      return true;
    }

    // traverse right subtree
    return inorderTraversal(root->right, k, result);
  }

  bool reverseInorderTraversal(TreeNode *root, int &k, int &result)
  {
    if (!root)
      return false;
    // traverse right subtree first
    if (reverseInorderTraversal(root->right, k, result))
      return true;

    if (--k == 0)
    {
      result = root->data;
      return true;
    }

    return reverseInorderTraversal(root->left, k, result);
  }
};
int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);

  Solution solution;
  int k = 1;
  vector<int> result = solution.kLargesSmall(root, k);

  // Output the result
  cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [1, 4]

  return 0;
}
