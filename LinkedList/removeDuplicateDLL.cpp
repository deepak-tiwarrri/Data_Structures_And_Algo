#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *next;
   Node *prev;

public:
   Node()
   {
      data = 0;
      next = nullptr;
      prev = nullptr;
   }
   Node(int data1, Node *next1, Node *prev1)
   {
      data = data1;
      next = next1;
      prev = prev1;
   }
   Node(int data1)
   {
      data = data1;
      next = nullptr;
      prev = nullptr;
   }
};
Node *convertArr2DLL(vector<int> arr)
{
   Node *head = new Node(arr[0]);
   Node *prev = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i], nullptr, prev);
      prev->next = newNode;
      prev = newNode;
   }
   return head;
}
void printDLL(Node *head)
{
   Node *temp = head;
   while (temp != nullptr)
   {
      cout << temp->data << "<->";
      temp = temp->next;
   }
   cout << "nullptr";
   cout << endl;
}
Node *removeDuplicates(Node *head)
{
   
}
int main()
{
   // code here
   int n, target;
   cin >> n >> target;
   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      ans.push_back(x);
   }
   Node *head = convertArr2DLL(ans);
   //   head = reverseDLL(head);
   // head = oddEvenList(head);
   // head = sort012List(head);
   head = removeDuplicates(head);

   printDLL(head);
   return 0;
}