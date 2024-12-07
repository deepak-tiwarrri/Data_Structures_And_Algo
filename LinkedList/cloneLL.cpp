#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *next;
   Node *random;
   Node() : data(0), next(nullptr), random(nullptr) {};
   Node(int x) : data(x), next(nullptr), random(nullptr) {};
   Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};
void *insertCopyinBetween(Node *head)
{
   Node *temp = head;
   while (temp != nullptr)
   {
      Node *copyNode = new Node(temp->data);
      copyNode->next = temp->next;
      temp->next = copyNode;
      temp = temp->next->next;
   }
}
void *connectRandomPointer(Node *head)
{
   Node *temp = head;
   while (temp)
   {
      Node *copyNode = temp->next;
      if (temp->random)
         copyNode->random = temp->random->next;
      else
         copyNode->random = nullptr;
      temp = temp->next->next;
   }
}
Node *getDeepCopyList(Node *head)
{
   Node *temp = head;
   Node *dummyNode = new Node(-1);
   Node *res = dummyNode;
   while (temp)
   {
      res->next = temp->next;
      res = res->next;
      temp->next = temp->next->next;
      temp = temp->next;
   }
   return dummyNode->next;
}
Node *cloneLL(Node *head)
{
   // Node *temp = head;
   // unordered_map<Node *, Node *> mpp;
   // while (temp)
   // {
   //    Node *copyNode = new Node(temp->data);
   //    mpp[temp] = copyNode;
   //    temp = temp->next;
   // }
   // temp = head;
   // while (temp)
   // {
   //    Node *copyNode = mpp[temp];
   //    copyNode->next = mpp[temp->next];
   //    copyNode->random = mpp[temp->random];
   //    temp = temp->next;
   // }
   // return mpp[head]; TC: O(2N) SC: O(n)+O(n)

   // optimal approach
   // insert the node in between
   // move to make random pointer point to random pointer
   // remove the new list and reverse the changes that have prevously altered the list

   // make a copynode and points it's random pointer
   if (!head)
      return nullptr;
   insertCopyinBetween(head);
   // now point the random pointer of copyed node
   connectRandomPointer(head);

   // now get the deep copy and remove the links
   return getDeepCopyList(head);
}
void printClonedLinkedList(Node *head)
{
   while (head != nullptr)
   {
      cout << "Data: " << head->data;
      if (head->random != nullptr)
      {
         cout << ", Random: " << head->random->data;
      }
      else
      {
         cout << ", Random: nullptr";
      }
      cout << endl;
      // Move to the next node
      head = head->next;
   }
}

int main()
{
   // code here
   // Example linked list: 7 -> 14 -> 21 -> 28
   Node *head = new Node(7);
   head->next = new Node(14);
   head->next->next = new Node(21);
   head->next->next->next = new Node(28);

   // Assigning random pointers
   head->random = head->next->next;
   head->next->random = head;
   head->next->next->random = head->next->next->next;
   head->next->next->next->random = head->next;

   cout << "Original Linked List with Random Pointers:" << endl;
   printClonedLinkedList(head);

   return 0;
}