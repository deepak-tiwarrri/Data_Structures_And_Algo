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
Node *removeNthFromEnd(Node *head, int n)
{
   // if (head == nullptr)
   //    return head;
   // if (head->next == nullptr && n == 1)
   //    return nullptr;
   // int cnt = 0;
   // Node *temp = head;
   // Node *prevNode = nullptr;
   // while (temp != nullptr)
   // {
   //    cnt++;
   //    temp = temp->next;
   // }
   // if (cnt == n)
   //    return head->next;
   // int res = cnt - n;
   // temp = head;
   // for (int i = 1; i <= res; i++)
   // {
   //    prevNode = temp;
   //    temp = temp->next;
   // }
   // prevNode->next = temp->next;
   // temp->next = nullptr;
   // delete (temp);
   // return head;

   // optimal approach
   Node *fast = head;
   Node *slow = head;
   for (int i = 0; i < n; i++)
      fast = fast->next;
   // it means that n is equal to the lenth of the linked list
   //  it means head have to be removed
   if (fast == nullptr)
      return head->next;
   while (fast->next != nullptr)
   {
      fast = fast->next;
      slow = slow->next;
   }
   Node *nodeToDelete = slow->next;
   slow->next = slow->next->next;
   nodeToDelete->next = nullptr;
   delete (nodeToDelete);
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
   head = removeNthFromEnd(head, k);
   printNode(head);

   return 0;
}