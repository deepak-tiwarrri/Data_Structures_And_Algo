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
   int currSize = 0;
   Node *start = nullptr;
   Node *end = nullptr;

public:
   void push(int x)
   {
      Node *temp = new Node(x);
      if (start == nullptr && end == nullptr)
      {
         start = end = temp;
      }
      else
      {  
         end->next = temp;
         end = temp;
      }
      currSize += 1;
   }
   int pop()
   {
      if(!start) return -1;
      Node *temp = start;
      int poppedVal = start->data;
      start = start->next;
      currSize -= 1;
      return poppedVal;
   }
   int top()
   {
      if (start == nullptr)
         return -1;
      return start->data;
   }
   int size()
   {
      return currSize;
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
