#include<bits/stdc++.h>
using namespace  std;
void printElementStack(stack<int> &s){
   while(!s.empty()){
      cout<<s.top()<<endl;
      s.pop();
   }
}
int main(){
   //code here
    
   int n;
   cin>>n;
   stack<int> s;
   s.push(5);
   s.push(19);
   while(!s.empty()){
      cout<<s.top()<<endl;
      s.pop();
   }
    return 0;
}