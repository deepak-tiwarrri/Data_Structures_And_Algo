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
   int size;
   Node* topPointer;
   Stack()
   {
      topPointer = nullptr;
      size = 0;
   }
   void push(int x)
   {

      Node* temp = new Node(x);
      temp->next = topPointer;
      topPointer = temp;
      size++;
   }
   int pop()
   {
      if(size==0) return -1;
      Node* temp = topPointer;
      int element = temp->data;
      topPointer = topPointer->next;
      size--;
      delete(temp);
      return element;
   }
   int top()
   {
      if(size==0) return -1;
      return topPointer->data;
   }
   int Size()
   {
      return size;
   }
   bool isEmpty(){
      return (size==0);
   }
   void printStackNode(){
      Node* temp = topPointer;
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
   cout << "size of stack" <<" "<< stt.Size() << endl;
   stt.printStackNode();
   return 0;
}