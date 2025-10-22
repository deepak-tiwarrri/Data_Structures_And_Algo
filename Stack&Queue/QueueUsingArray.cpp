// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
class Queue {
private:
   int currSize;
   int start;
   int end;
   int currentSize;
   int size;
   int* arr;
public:
   Queue(int capacity = 10) {
      size = capacity;
      currSize = 0;
      start = -1;
      end = -1;
      currentSize = 0;
      arr = new int[size];
   }
   void push(int x) {
      //if start and end are both at -1
      //then only increase the start and not the end
      if (start == -1 && end == -1) {
         start++;
      }
      end++;
      currSize++;
      arr[end % size] = x;

   }
   int pop() {
      if (start == end) {
         //means both are at same index and queue is empty
         cout << "Queue is empty" << endl;
         return -1;
      }
      //we u are popping and start and end become equal then it means no value is present

      if (currSize == 0) {
         start = -1;
         end = -1;
      }
      int poppedVal = arr[start % size];
      //if popped then start will increase
      start++;
      currSize--;
      return poppedVal;
   }
   int Size() {
      return currSize;
   }
   int top() {
      if (start == -1) {
         return -1;
      }
      int topVal = arr[start % size];
      return topVal;

   }
};

int main() {
   // Write C++ code here
   // std::cout << "Try programiz.pro";
   Queue q;
   q.push(39);
   q.push(383);
   q.push(8);
   cout << q.top() << endl;
   cout << q.Size() << endl;
   cout << q.pop() << endl;
   cout << q.Size() << endl;
   cout << q.top() << endl;

   return 0;
}