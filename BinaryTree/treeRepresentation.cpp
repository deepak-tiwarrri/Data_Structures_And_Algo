#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node *right;

   Node(int data1, Node *left1, Node *right1)
   {
      data = data1;
      left = left1;
      right = right1;
   }
   Node(int data1)
   {
      data = data1;
      left = nullptr;
      right = nullptr;
   }
};
int main()
{
   // code here
   Node *root = new Node(1);
   root->left = new Node(6);
   root->right = new Node(9);
   root->left->right = new Node(10);
   root->left->left = new Node(5);
   return 0;
}