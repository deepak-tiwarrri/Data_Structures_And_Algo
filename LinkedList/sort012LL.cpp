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
Node *findIntersection(Node *slow, Node *fast)
{
   while (slow != fast)
   {
      slow = slow->next;
      fast = fast->next;
   }
   return fast;
}

Node *sortList(Node *head)
{
   // brute force approach
   // TC: O(2N) SC: O(1)
   // int cnt0 = 0, cnt1 = 0, cnt2 = 0;
   // Node *temp = head;
   // while (temp != nullptr)
   // {
   //    if (temp->data == 0)
   //       cnt0++;
   //    else if (temp->data == 1)
   //       cnt1++;
   //    else
   //       cnt2++;
   //    temp = temp->next;
   // }
   // temp = head;
   // while (temp)
   // {
   //    if (cnt0 > 0)
   //    {
   //       temp->data = 0;
   //       cnt0--;
   //    }
   //    else if (cnt1 > 0)
   //    {
   //       temp->data = 1;
   //       cnt1--;
   //    }
   //    else
   //    {
   //       temp->data = 2;
   //       cnt2--;
   //    }
   //    temp = temp->next;
   // }
   // return head;
   if (head == nullptr || head->next == nullptr)
      return head;
   Node *dummyNode0 = new Node(-1);
   Node *dummyNode1 = new Node(-1);
   Node *dummyNode2 = new Node(-1);
   Node *temp0 = dummyNode0;
   Node *temp1 = dummyNode1;
   Node *temp2 = dummyNode2;
   Node *temp = head;
   while (temp != nullptr)
   {
      if (temp->data == 0)
      {
         temp0->next = temp;
         temp0 = temp0->next;
      }
      else if (temp->data == 1)
      {
         temp1->next = temp;
         temp1 = temp1->next;
      }
      else if (temp->data == 2)
      {
         temp2->next = temp;
         temp2 = temp2->next;
      }
      temp = temp->next;
   }
   temp0->next = (dummyNode1->next) ? (dummyNode1->next) : (dummyNode2->next);
   temp1->next = (dummyNode2->next);
   temp2->next = nullptr;
   return dummyNode0->next;
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
   // printNode();

   return 0;
}