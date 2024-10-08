#include<bits/stdc++.h>
class Node
{
public:
int data;
Node* next;

public:

   Node(int data1,Node* next1) {
      data = data1;
      next = next1;
   }

public:
   Node(int data1){
      data = data1;
      next = nullptr;
   }

};
using namespace  std;
Node* convertArr2all(vector<int> &arr){
   Node* head  = new Node(arr[0]);
   Node* temp = head;
   for(int i=1;i<arr.size();i++){
      Node* newTemp = new Node(arr[i]);
      temp->next = newTemp;
      temp = newTemp;
   }
   return head;
}
void printNode(Node* head){
   Node* temp = head;
   while(temp!=nullptr){
      // cout<<temp->val<<"-->";
      cout<<temp->data<<"->";
      temp = temp->next;
   }
   cout<<"null";
   cout<<endl;
}
Node* insertAtFirst(int value,Node* head){
   Node* temp = new Node(value);
   temp->next = head;
   head = temp;
   return head;
}
Node* removeHead(Node *head){
   //delete the head of linkes list
   if(head==nullptr)return head;
   Node* temp = head;
   //point head to next and delete temp
   head = head->next;
   delete temp;
   return head;
}
Node* insertAtTail(Node* head,int x){
   if(head==nullptr) return new Node(x);
   Node* temp = head;
   while(temp->next!=nullptr){
      temp = temp->next;
   }
   temp->next = new Node(x);
   return head;
}
Node* deleteTail(Node* head){
   if(head==nullptr || head->next==nullptr) return nullptr;
   Node* temp = head;
   while(temp->next->next!=nullptr){
      temp=temp->next;
   }
   delete temp->next;
   temp->next = nullptr;
   return head;
}
Node* removeKthNode(Node* head,int k){
   if(head==NULL) return NULL;
   if(k==1) return removeHead(head);
   int cnt=0;
   Node* temp = head;
   while(temp!=NULL && cnt<=k-1){
      cnt++;
      if(cnt==k-1) break;
      temp=temp->next;
   }
   if(cnt<k) return head;
   Node* delNode = temp->next;
   temp->next = temp->next->next;
   delete delNode;
   return head;
}
int main(){
   //code here
   int n;
   cin>>n;
   vector<int> arr;
   for (int ele = 0; ele < n; ele++)
   {
      int x;
      cin>>x;
      arr.push_back(x);
   }
   
   Node*  head = convertArr2all(arr);
   // Node* head = NULL;
   insertAtFirst(2,head);
   // insertAtFirst(8,head);
   // insertAtFirst(10,head);
   // insertAtFirst(11,head);
   // head = removeHead(head);
   // head = removeKthNode(head,8);
   // head = insertAtTail(head,4);
   printNode(head);
    return 0;
}