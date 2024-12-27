#include <bits/stdc++.h>
using namespace std;
class Stack
{
   int *stackArray;
   int topPointer,capacity,stackSize=0;

public:
   // make constructor
   Stack(int size=1000)
   {
     topPointer = -1;
     capacity = size;
     stackArray = new int[capacity];

   }
   void push(int x)
   {
      if(stackSize>=capacity-1)return;
      topPointer++;
      stackArray[topPointer] = x;
      stackSize++;
   }
   int pop()
   {
      if(stackSize==0) return -1;
      //else pop
      int element = stackArray[topPointer];
      topPointer--;
      stackSize--;
      return element;
   }
   int top()
   {
      return stackArray[topPointer];
   }
   int size()
   {
      return stackSize;
   }
   bool isEmpty(){
      return (stackSize==0);
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