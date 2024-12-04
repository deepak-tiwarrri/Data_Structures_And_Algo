// write the code to check if the given linkedlist is palindrome or not
//  write the code for it in cpp

#include <bits/stdc++.h>
class Node
{
public:
   int data;
   Node *next;

public:
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
   Node(int data1, Node *next1)
   {
      data = data1;
      next = next1;
   }
};

using namespace std;
void printList(Node *head)
{
   Node *temp = head;
   while (temp)
   {
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "nullptr";
}
Node *convert2LL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *temp = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i]);
      temp->next = newNode;
      temp = newNode;
   }
   return head;
}
Node *reverseLL(Node *head)
{
   if (head == nullptr || head->next == nullptr)
      return head;
   Node *newHead = reverseLL(head->next);
   Node *front = head->next;
   front->next = head;
   head->next = nullptr;
   return newHead;
}

Node *rotateKTimeLL(Node *head, int k)
{
   // rotate by 2 means put last k elmeent to first;
   // first find the length and last node
   // make lastnode point to  head
   // find the last k node and point head to lastKnode->next
   // now lastKnode->next = nullptr
   if (head == nullptr || head->next == nullptr || k == 0)
      return head;
   Node *tail = head;
   int len = 1;
   while (tail->next != nullptr)
   {
      /* code */
      tail = tail->next;
      len++;
   }
   if (k % len == 0)
      return head;
   tail->next = head;
   k = k % len;
   // now find the last k node
   int res = len - k;
   tail = head;
   res--;
   while (res > 0 && tail != nullptr)
   {
      res--;
      tail = tail->next;
   }
   head = tail->next;
   tail->next = nullptr;
   return head;
}
int main()
{
   int n, k;
   cin >> n >> k;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }

   Node *head = convert2LL(nums);
   head = rotateKTimeLL(head, k);
   printList(head);
}
