// queue using linked list
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
class Queue
{
   public:
   int queueSize = 0;
   Node* start = NULL;
   Node* end = NULL;
public:
   void push(int x)
   {
      //create a new linked list
      Node* topPointer = new Node(x);
      end->next = topPointer;
      if(start==nullptr){
         start = topPointer;
      }
      end = topPointer;
      queueSize++;

   }
   int pop()
   {
     if(start==nullptr) return -1;
     if(start==end && queueSize==1){
         start = nullptr;
         end = nullptr;
         return -1;
     }
     //point temp  to start and then delete the temp
     Node* temp = start;
     int popValue = temp->data;
     start = start->next;
     queueSize--;
     delete temp;
      return popValue;
   }
   int top()
   {
      if (start == nullptr)
         return -1;
      return start->data;
   }
   int size()
   {
      return queueSize;
   }
   bool isEmpty(){
      if(start==nullptr) return -1;
      return queueSize==0;//start=end=nullptr;
   }
   void printStackNode()
   {
      Node *temp = start;
      while (temp!= nullptr)
      {
         cout << temp->data << " ";
         temp = temp->next;
      }
   }
};
int main()
{
   Queue qq;
   qq.push(9);
   qq.push(7);
   qq.push(8);
   cout << "popped value " << " " << qq.pop() << endl;
   cout << "top value " << qq.top() << endl;
   cout << "size of queue " << qq.size() << endl;
   qq.push(19);
   qq.push(29);
   qq.printStackNode();
}
