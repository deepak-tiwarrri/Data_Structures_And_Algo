class Node
{
public:
   int data;
   Node *next;
   Node *prev;

public:
   Node(int data1, Node *next1, Node *prev1)
   {
      data = data1;
      next = next1;
      prev = prev1;
   }

public:
   Node(int data1)
   {
      data = data1;
      next = nullptr;
      prev = nullptr;
   }
};
#include <bits/stdc++.h>
using namespace std;
Node *insertBeforeHead(Node *head, int val)
{
   Node *newNode = new Node(val, head, nullptr);
   head->prev = newNode;
   return newNode;
}
Node *insertBeforeTail(Node *head, int k)
{
   // Write your code here
   Node *newNode = new Node(k);

   if (head == nullptr)
      return newNode;
   if(head->next==nullptr){
      return insertBeforeHead(head,k);
   }
   Node *temp = head;
   while (temp->next != nullptr)
      temp = temp->next;
   Node *prev = temp->prev;
   newNode->next = temp;
   temp->prev = newNode;
   prev->next = newNode;
   newNode->prev = prev;
   return head;
}
Node *deleteHead(Node *head)
{
   if (head == nullptr || head->next == nullptr)
      return nullptr;
   Node *prev = head;
   head = head->next;
   prev->next = nullptr;
   head->prev = nullptr;
   free(prev);
   return head;
}
Node *deleteTail(Node *head)
{
   if (head == nullptr || head->next == nullptr)
   {
      delete head;
      return nullptr;
   }
   Node *temp = head;
   while (temp->next != nullptr)
   {
      temp = temp->next;
   }
   Node *prev = temp->prev;
   prev->next = nullptr;
   delete temp;
   return head;
}
Node *deleteKthElement(Node *head, int k)
{
   if (head == nullptr)
      return nullptr;
   int cnt = 0;
   Node *temp = head;
   while (temp != nullptr && cnt < k)
   {
      cnt += 1;
      if (cnt == k)
         break;
      temp = temp->next;
   }
   Node *prev = temp->prev;
   Node *front = temp->next;
   if (prev == nullptr && front == nullptr)
      return nullptr;
   else if (prev == nullptr)
      return deleteHead(head);
   else if (front == nullptr)
      return deleteTail(head);
   prev->next = front;
   front->prev = prev;
   temp->prev = nullptr;
   temp->next = nullptr;
   delete temp;
   return head;
}
void deleteNode(Node *temp)
{
   // given node delete that node
   Node *prev = temp->prev;
   Node *front = temp->next;
   if (front == nullptr)
   {
      prev->next = nullptr;
      temp->prev = nullptr;
      delete temp;
   }
   prev->next = front;
   front->prev = prev;
   temp->next = nullptr;
   temp->prev = nullptr;
   delete temp;
}
Node *convert2DLL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *temp = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i], nullptr, temp);
      temp->next = newNode;
      temp = newNode;
   }
   return head;
}
void printDLL(Node *head)
{
   while (head != nullptr)
   {
      cout << head->data << " ";
      head = head->next;
   }
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   Node *head = convert2DLL(arr);
   //  Node* temp = insertAtail(head,20);
   // head = deleteHead(head);
   // head = insertAtTail(head,3);
   // head = deleteKthElement(head, 6);
   // deleteNode(head->next);
   // head = insertBeforeHead(head, 39);
   head = insertBeforeTail(head,20);
   printDLL(head);
   return 0;
}
