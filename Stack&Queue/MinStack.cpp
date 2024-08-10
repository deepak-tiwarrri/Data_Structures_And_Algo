#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
   // stack<pair<int, int>> stPair;
   stack<long long> st;
      long long mini;
   MinStack()
   {
   }

   void push(int val)
   {
      // if (stPair.empty())
      // {
      //    mini = val;
      // }
      // stPair.push({val, min(stPair.top().second, val)});
      long long value = (long long )val;
      if(st.empty()){
         st.push(value);
         mini = value;
      }
      if(value<st.top()){
         mini = value;
         st.push((2*value*1LL-mini));
      }
   }

   void pop()
   {
      // stPair.pop();
      if(st.empty()) return;
      if(st.top()<mini){
         mini = 2*mini - st.top();
         st.pop();
      }else{
         st.pop();
      }
   }

   int top()
   {
      // return stPair.top().first;
      if(st.empty()) return -1;
      if(st.top()<mini) return mini;
      return st.top();
   }

   int getMin()
   {
      // return stPair.top().second;
      return mini;
   }
};
int main()
{
   // code here
   MinStack obj;
   obj.push(9);
   obj.push(10);
   obj.push(12);
   cout << "minimum " << obj.getMin() << endl;
   obj.push(8);
   cout << "top value " << obj.top() << endl;
   obj.pop();
   obj.pop();
   cout << "top value " << obj.top() << endl;
   cout << "minimum " << obj.getMin() << endl;

   return 0;
}
/**
 * Your MinStack object will be instantiated and called as such:
//  MinStack* obj = new MinStack();
//  obj->push(val);
//  obj->pop();
//  int param_3 = obj->top();
//  int param_4 = obj->getMin();
 */