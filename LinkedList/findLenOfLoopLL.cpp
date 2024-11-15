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
int findLength(Node *slow, Node *fast)
{
   int cnt = 1;
   fast = fast->next;
   while (fast != slow)
   {
      cnt++;
      fast = fast->next;
   }
   return cnt;
}
int findLengthOfLoop(Node *head)
{
   // brute force approach using timer
   // TC: O(n) and SC: O(n)
   // unordered_map<Node *, int> nodeMap;
   // Node *temp = head;
   // int timer = 1;
   // while (temp != nullptr)
   // {
   //    if (nodeMap.find(temp) != nodeMap.end())
   //    {
   //       // if we got the node then
   //       int val = nodeMap[temp];
   //       return (timer - val);
   //    }
   //    nodeMap[temp] = timer;
   //    timer++;
   //    temp = temp->next;
   // }
   // optimal approach using hare and tortoise
   Node *slow = head;
   Node *fast = head;
   while (fast != nullptr && fast->next != nullptr)
   {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
         return findLength(slow, fast);
      }
   }

   return 0;
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
   int res = findLengthOfLoop(head);
   cout << res << endl;
   // printNode(head);

   return 0;
}