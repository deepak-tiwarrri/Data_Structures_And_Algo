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
      if(st.empty()) st.push(val);
      else{
         if(val>mini){
            st.push(val);
         }else{
            //else val is less
            st.push((2*1LL*val-mini));
            mini = val;
         }
      }
   }

   void pop()
   {
      // stPair.pop();
      if(st.empty()) return;
      long long x = st.top();
      st.pop();
      if(x<mini){
         //i have to changge the mini
         mini = 2*mini-x;
      }
   }

   int top()
   {
      // return stPair.top().first;
      if(st.empty()) return -1;
      if(st.top()<mini) return mini;
      else return st.top();
   }

   int getMin()
   {
      // return stPair.top().second;
      if(st.empty()) return -1;
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