#include<bits/stdc++.h>
using namespace  std;
class Queue{
   private:
   int currSize,start,end,size;
   int *arr;
   public:
   Queue(){
      size = 16;
      arr = new int[size];
      start = -1;
      end = -1;
      currSize = 0;
   }
   void push(int x){
      if(start==-1 && end==-1) start++;
   //also if(end = -1) then it means that 
      end++;
      currSize++;
      arr[end%size] = x;
      //end = (end+1)%size
   }
   int pop(){
      if(start==end) return -1;
      int popped = arr[start];
      if(currSize==-1){
         start = -1;
         end = -1;
      }
      currSize--;
      start++;
      return popped;
   }
   int top(){
      return arr[start];
   }
   int Size(){
      return currSize;
   }
};
int main(){
   //code here
    Queue q;
    q.push(39);
    q.push(383);
    q.push(8);
    cout<<q.top()<<endl;
    cout<<q.Size()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.Size()<<endl;
    cout<<q.top()<<endl;
    return 0;
}