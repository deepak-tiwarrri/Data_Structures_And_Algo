#include <bits/stdc++.h>
using namespace std;
class Stack
{
   int *arr;
   int tpp, currSize, sz;

public:
   // make constructor
   Stack()
   {
      tpp = -1;
      sz = 10;
      currSize = 0;
      arr = new int[sz];
   }
   void push(int x)
   {
      if (currSize == sz)
      {
         cout << "stack is full";
         return;
      }
      tpp++;
      arr[tpp] = x;
      currSize++;
   }
   int pop()
   {
      if (currSize == 0)
      {
         cout << "stack is empty"<<endl;
         return -1;
      }
      int val = arr[tpp];
      tpp--;
      currSize--;
      return val;
   }
   int top()
   {
      return arr[tpp];
   }
   int size()
   {
      return currSize;
   }
};
int main()
{
   // code here
   Stack st;
   st.push(20);
   st.push(10);
   st.push(5);
   cout<<st.pop()<<endl;
   cout<<st.top()<<endl;
   cout<<st.size()<<endl;
   st.push(9);
   st.push(87);
   st.push(90);
   st.push(81);
   st.push(86);
   st.push(86);
   st.push(86);
   st.push(88);
   st.push(9898);
   cout<<st.size()<<endl;
   return 0;
}