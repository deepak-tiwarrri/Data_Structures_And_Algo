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

   if (head == nullptr || head->next == nullptr)
      return head;
   Node *newHead = reverseList(head->next);
   Node *front = head->next;
   front->next = head;
   // head->next = front;
   head->next = nullptr;
   return newHead;
}
Node *findKthNode(Node *head, int k)
{
   Node *temp = head;
   k--;
   while (temp != nullptr && k > 0)
   {
      temp = temp->next;
      k--;
   }
   return temp;
}
Node *reverseKGroup(Node *head, int k)
{
   Node *temp = head;
   Node *prevNode = nullptr;
   while (temp != nullptr)
   {
      Node *kthNode = findKthNode(temp, k);
      // if kthnode is there then point it to the nullptr
      if (kthNode == nullptr)
      {
         if (prevNode)
            prevNode->next = temp;
         break;
      }
      Node *nextNode = kthNode->next;
      reverseList(temp);
      if (temp == head)
      {
         head = kthNode;
      }
      else
      {
         prevNode->next = nextNode;
      }

      prevNode = temp;
      temp = nextNode;
   }
   return head;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> arr;
   for (int ele = 0; ele < n; ele++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   Node *head = convertArr2all(arr);
   head = reverseKGroup(head, k);
   printNode(head);
   return 0;
}