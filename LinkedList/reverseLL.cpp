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
Node *reverseList(Node *head)
{
   // optimal recursive approach
   //  Node* last =nullptr;
   //  Node* temp = head;
   //  while (temp!=nullptr)
   //  {
   //     Node* nextNode = temp->next;
   //     temp->next = last;
   //     last = temp;
   //     temp = nextNode;
   //  }
   //  return last;
   if (head == nullptr || head->next == nullptr)
      return head;
   Node *newHead = reverseList(head->next);
   Node *front = head->next;
   front->next = head; 
   // head->next = front;
   head->next = nullptr;
   return newHead;
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

   Node *head = convertArr2all(arr);
   // head = oddEvenList(head);
   head = reverseList(head);
   printNode(head);

   return 0;
}