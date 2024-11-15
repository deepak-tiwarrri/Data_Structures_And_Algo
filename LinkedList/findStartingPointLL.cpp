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
Node *findIntersection(Node *slow, Node *fast)
{
   while (slow != fast)
   {
      slow = slow->next;
      fast = fast->next;
   }
   return fast;
}
Node *findStartingPoint(Node *head)
{
   if (head == nullptr || head->next == nullptr)
      return head;
   Node *slow = head;
   Node *fast = head;
   while (fast != nullptr || fast->next != nullptr)
   {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
         slow = head;
         return findIntersection(slow, fast);
      }
   }
   return nullptr;
   // unordered_map<Node *, int> mpp;
   // Node *temp = head;

   // while (temp != nullptr)
   // {
   //    if (mpp.find(temp) != mpp.end())
   //    {
   //       return temp;
   //    }
   //    mpp[temp] = 1;
   //    temp = temp->next;
   // }
   // return NULL;
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
   lastNode->next = head->next->next->next;
   Node *newNode = findStartingPoint(head);
   cout << newNode->data;
   // printNode();

   return 0;
}