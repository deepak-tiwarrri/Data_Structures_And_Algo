#include <bits/stdc++.h>
using namespace std;
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
bool isPalindrome(Node *head)
{
   if (head == nullptr || head->next == nullptr)
      return true;

   Node *slow = head;
   Node *fast = head;
   while (fast->next && fast->next->next)
   {
      slow = slow->next;
      fast = fast->next->next;
   }

   // reverse the half linked list
   Node *newHead = reverseLL(slow->next);
   Node *first = head;
   Node *second = newHead;
   while (second != nullptr)
   {
      if (second->data != first->data)
      {
         reverseLL(newHead);
         return false;
      }
      second = second->next;
      first = first->next;
   }
   reverseLL(newHead);
   return true;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   Node *head = convert2LL(nums);
   bool isPalindromic = isPalindrome(head);
   if (isPalindromic)
      cout << "Palidrome" << endl;
   else
      cout << "Not Palindrom" << endl;
   printList(head);
   return 0;
}