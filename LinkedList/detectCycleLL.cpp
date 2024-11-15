// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

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
bool hasCycle(Node *head)
{
   Node *slow = head;
   Node *fast = head;
   while (fast != nullptr && fast->next != nullptr)
   {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
         return true;
   }
   return false;
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
   Node *lastNode = head;
   while (lastNode->next != nullptr)
   {
      lastNode = lastNode->next;
   }
   lastNode->next = head->next;
   bool isCycle = hasCycle(head);
   isCycle ? cout << "true" : cout << "false" << endl;
   // printNode(head);

   return 0;
}