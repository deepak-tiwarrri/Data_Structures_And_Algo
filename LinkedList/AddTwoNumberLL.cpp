#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *next;

public:
   Node(int data1, Node *next1)
   {
      data = data1;
      next = next1;
   }

public:
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
};
Node *addTwoNumbers(Node *l1, Node *l2)
{
   int carry = 0;
   int sum = 0;
   Node *dummyNode = new Node(-1);
   Node *temp = dummyNode;
   while (l1 != nullptr || l2 != nullptr)
   {
      sum = carry;
      if (l1)
      {
         sum += l1->data;
         l1 = l1->next;
      }
      if (l2)
      {
         sum += l2->data;
         l2 = l2->next;
      }
      carry = sum/10;
      Node *newNode = new Node(sum % 10);
      temp->next = newNode;
      temp = temp->next;//movie temp to next node
   }
   if(carry){
      Node* newNode = new Node(carry%10);
      temp->next = newNode;
   }
   return dummyNode->next;
}
Node *convertArr2all(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *temp = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *newTemp = new Node(arr[i]);
      temp->next = newTemp;
      temp = newTemp;
   }
   return head;
}
void printNode(Node *head)
{
   Node *temp = head;
   while (temp != nullptr)
   {
      // cout<<temp->val<<"-->";
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "null";
   cout << endl;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr;
   for (int ele = 0; ele < n; ele++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
m
   Node *head = convertArr2all(arr);
   // Node* head = NULL;
   printNode(head);
   return 0;
}