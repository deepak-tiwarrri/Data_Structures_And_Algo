#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node* right;

public:
   Node(int data, Node *left = nullptr, Node *right = nullptr)
   {
      this->data = data;
      this->left = left;
      this->right = right;
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