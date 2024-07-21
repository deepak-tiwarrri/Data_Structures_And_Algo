#include<bits/stdc++.h>
using namespace  std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int sz = q.size();
        for(int i=0;i<sz;i++){
            q.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
      //   int val = q.rear();
      //   return val;
    }
    
    bool empty() {
        return q.empty();
    }
};
int main(){
   //code here
    
   MyStack mystack;
   mystack.push(9);
   mystack.push(7);
   mystack.push(8);
   mystack.pop();
   mystack.top();
   mystack.push(19);
    return 0;
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */