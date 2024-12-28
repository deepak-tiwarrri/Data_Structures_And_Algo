//stack using queue

using namespace std;
#include <bits/stdc++.h>
class QueueStack{
    public:
    queue<int> q;
    QueueStack(){

    }
    void push(int x){
        int size = q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int data = q.front();
        q.pop();
        return data;
    }
    int top(){
        return q.front();
    }
    int isEmpty(){
        return q.empty();
    }
    int size(){
        return q.size();
    }

};
int main() {
    // code here
   cin.tie(0);cout.tie(0);
    QueueStack qs;
    qs.push(9);
    qs.push(5);
    qs.push(10);
    qs.top();
    qs.pop();
    qs.top();


    return 0;
}