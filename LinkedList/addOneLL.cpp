// add one to the linked list
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
int addHelper(Node *temp)
{
   if (temp == nullptr)
   {
      // it means we are at end of the linked list
      return 1;
   }
   int carry = addHelper(temp->next);
   temp->data = temp->data + carry;
   if (temp->data < 10)
      return 0; // it means carry is not there
   // it means that carry is there and now temp data should be 0
   temp->data = 0;
   // if(temp->data>10) temp->data = 0;
   return 1;
}
Node *addOne(Node *head)
{
   // better approach use reverse function
   // first reverse the ll then add the carry then also reverse the array
   // if all the elment become zero and carry is left at the end
   // then insert 1 before head and make this node as head
   //   head = reverseList(head);
   //   int carry = 1;
   //   Node* temp = head;
   //   while(temp!=nullptr){
   //       int sum = temp->data + carry;
   //       carry = sum/10;
   //       temp->data = sum%10;
   //       if(carry==0){
   //           break;
   //       }
   //       //if we react the end and carry is zero than make the new node and insert it
   //       if(temp->next==nullptr && carry!=0){
   //           temp->next = new Node(carry);
   //           break;
   //       }
   //       temp = temp->next;
   //   }

   //   //if not is the case then reverse the linked list
   //   head = reverseList(head);
   //   return head;

   // optimal approach using recursion and backtracking
   int carry = addHelper(head);
   if (carry == 1)
   {
      // at last carry is one then add one to the first node
      Node *newNode = new Node(carry);
      newNode->next = head;
      return newNode;
   }
   return head;
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
   head = addOne(head);
   printNode(head);

   return 0;
}