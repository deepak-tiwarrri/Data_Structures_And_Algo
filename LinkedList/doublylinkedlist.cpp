#include <iostream>
#include <vector>
using namespace std;
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

Node *insertBeforeHead(Node *head, int val)
{
   Node *newNode = new Node(val, head, nullptr);
   if (head != nullptr)
      head->prev = newNode;
   return newNode;
}
Node *insertBeforeTail(Node *head, int k)
{
   Node *newNode = new Node(k);

   if (head == nullptr)
      return newNode;
   if (head->next == nullptr)
   {
      return insertBeforeHead(head, k);
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
   if (head == nullptr)
      return nullptr;
   if (head->next == nullptr)
   {
      delete head;
      return nullptr;
   }
   Node *prev = head;
   head = head->next;
   prev->next = nullptr;
   head->prev = nullptr;
   delete prev;
   return head;
}
Node *deleteTail(Node *head)
{
   if (head == nullptr)
   {
      return nullptr;
   }
   if (head->next == nullptr)
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
   if (head == nullptr || k <= 0)
      return head;
   int cnt = 0;
   Node *temp = head;
   while (temp != nullptr && cnt < k)
   {
      cnt += 1;
      if (cnt == k)
         break;
      temp = temp->next;
   }
   if (temp == nullptr)
      return head;
   Node *prev = temp->prev;
   Node *front = temp->next;
   if (prev == nullptr && front == nullptr)
   {
      delete temp;
      return nullptr;
   }
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
   if (temp == nullptr)
      return;
   Node *prev = temp->prev;
   Node *front = temp->next;
   if (prev == nullptr)
   {
      if (front != nullptr)
         front->prev = nullptr;
      delete temp;
      return;
   }
   if (front == nullptr)
   {
      prev->next = nullptr;
      temp->prev = nullptr;
      delete temp;
      return;
   }
   prev->next = front;
   front->prev = prev;
   temp->next = nullptr;
   temp->prev = nullptr;
   delete temp;
}
Node *convert2DLL(vector<int> &arr)
{
   if (arr.empty())
      return nullptr;
   Node *head = new Node(arr[0]);
   Node *temp = head;
   for (int i = 1; i < (int)arr.size(); i++)
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
   head = insertBeforeTail(head, 20);
   printDLL(head);
   return 0;
}
