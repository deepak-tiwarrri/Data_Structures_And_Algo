// stack using linked list
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
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
};
class Stack
{
public:
   int currSize;
   Node *topp;
   Stack()
   {
      currSize = 0;
      topp = NULL;
   }
   void push(int x)
   {
      Node *temp = new Node(x);
      temp->next = topp;
      topp = temp;
      cout << "element pushed" << endl;
      currSize++;
   }
   int pop()
   {
      if (topp == nullptr){
         // cout<<"stack is empty"<<endl;
         return -1;
      }
      int popped = topp->data;
      Node *temp = topp;
      topp = topp->next;
      delete temp;
      currSize--;
      return popped;
   }
   int top()
   {
      return topp->data;
   }
   int size()
   {
      return currSize;
   }
   void printStackNode(){
      Node* temp = topp;
      while(temp->next!=nullptr){
         cout<<temp->data<<" ";
         temp = temp->next;
      }
   }
};
int main()
{
   // code here
   Stack stt;
   stt.push(9);
   stt.push(89);
   stt.push(90);
   stt.push(3);
   stt.push(10);
   cout << "popped value" <<" "<< stt.pop()<<" " << endl;
   cout << "popped value" <<" "<< stt.pop()<<" " << endl;
   cout << "popped value" <<" "<< stt.pop()<<" " << endl;
   cout << "popped value" <<" "<< stt.pop()<<" " << endl;
   cout << "popped value" <<" "<< stt.pop()<<" " << endl;
   cout << "popped value" <<" "<< stt.pop()<<" " << endl;
   cout << "top value" <<" "<< stt.top()<<endl;
   cout << "size of stack" <<" "<< stt.size() << endl;
   stt.printStackNode();
   return 0;
}