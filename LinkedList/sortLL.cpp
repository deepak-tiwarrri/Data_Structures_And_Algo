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
      // cout<<temp->data<<"-->";
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "null";
   cout << endl;
}
Node *mergeTwoLL(Node *temp1, Node *temp2)
{

   Node *dummyNode = new Node(-1);
   Node *temp = dummyNode;
   while (temp1 != nullptr && temp2 != nullptr)
   {
      if (temp1->data <= temp2->data)
      {
         temp->next = temp1;
         temp1 = temp1->next;
      }
      else
      {
         temp->next = temp2;
         temp2 = temp2->next;
      }
      temp = temp->next;
   }
   if (temp1 != nullptr)
      temp->next = temp1;
   else
      temp->next = temp2;
   return dummyNode->next;
}
Node *findMiddleNode(Node *head)
{
   // find the first middle node not the second one
   // first the smallest portion then bigger portion
   Node *slow = head;
   Node *fast = head->next;
   while (fast != nullptr && fast->next != nullptr)
   {
      slow = slow->next;
      fast = fast->next->next;
   }

   return slow;
}
Node *sortList(Node *head)
{
   // Node *temp = head;
   // vector<int> arr;
   // while (temp)
   // {
   //    arr.push_back(temp->data);
   //    temp = temp->next;
   // }
   // sort(arr.begin(), arr.end());
   // temp = head;
   // int i = 0;
   // while (temp)
   // {
   //    temp->data = arr[i];
   //    temp = temp->next;
   //    i++;
   // }
   // return head;

   // base case for recursion of merge sort
   if (head == nullptr || head->next == nullptr)
      return head;
   Node *middleNode = findMiddleNode(head);
   Node *rightHead = middleNode->next;
   middleNode->next = nullptr;
   Node *leftHead = head;
   // don't forget to sort recursively the left half and the right half
   // it will divide itself multiple time
   leftHead = sortList(leftHead);
   rightHead = sortList(rightHead);
   // now make middleNOde next to nullptr to separate them
   return mergeTwoLL(leftHead, rightHead);
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
   head = sortList(head);
   printNode(head);

   return 0;
}