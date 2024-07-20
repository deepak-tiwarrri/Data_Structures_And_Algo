//stack using linked list
#include<bits/stdc++.h>
class Node{
   public:
   int data;
   Node *next;
   public:
   Node(int data1,Node* next1){
      data = data1;
      next = next1;
   }
   Node(int data1){
      data = data1;
      next = nullptr;
   }
};
class Stack{
   public:
   int currSize;
   Node* topp;
   Stack(){
      currSize = 0;
      
   }
};
using namespace  std;
int main(){
   //code here
    

    return 0;
}