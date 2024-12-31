#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
   stack<int> st1, st2;
   void push(int x)
   {
      // s1 to s2
      while (st1.size())
      {
         st2.push(st1.top());
         st1.pop();
      }
      // push to s2
      st2.push(x);
      // s2 to s1
      while (st2.size())
      {
         st1.push(st2.top());
         st2.pop();
      }
   }
   int pop()
   {
      int val = st1.top();
      st1.pop();
      return val;
   }
   int top()
   {
      return st1.top();
   }
   int size()
   {
      return st1.size();
   }
};
class QueueII
{
   // second approach with expensive top and pop operation
   // but push operation is easy
public:
   stack<int> s1, s2;
   void push(int x)
   {
      s1.push(x);
   }
   int pop()
   {
      if (!s2.empty())
      {
         int val = s2.top();
         s2.pop();
         return val;
      }
      while (s1.size())
      {
         s2.push(s1.top());
         s1.pop();
      }
      int val = s2.top();
      s2.pop();
      return val;
   }
   int top()
   {

      if (!s2.empty())
      {
         return s2.top();
      }
      while (s1.size())
      {
         s2.push(s1.top());
         s1.pop();
      }
      return s2.top();
   }
   int size()
   {
     return s1.size() + s2.size();
   }
};
int main()
{
   // code here
   QueueII qq;
   qq.push(39);
   qq.push(3);
   qq.push(49);
   qq.push(89);
   qq.push(1);
   cout << "popped element " << " " << qq.pop() << endl;
   cout << "popped element " << " " << qq.pop() << endl;
   cout << "top element" << " " << qq.top() << endl;
   cout << "size of queue" << " " << qq.size() << endl;
   cout << "popped element " << " " << qq.pop() << endl;
   cout << "size of queue" << " " << qq.size() << endl;
   qq.push(38389);
   qq.push(899);
   cout << "size of queue" << " " << qq.size() << endl;

   return 0;
}