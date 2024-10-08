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
Node* insertAtTail(Node* head,int x){
   if(head==nullptr) return new Node(x);
   Node* temp = head;
   while(temp->next!=nullptr){
      temp = temp->next;
   }
   temp->next = new Node(x);
   return head;
}
//u have to find X given and insert the given value before it
Node* insertBeforeX(int X,int val,Node* head){
   if(head==nullptr) return nullptr;
   if(head->data==X){
      return new Node(val,head);
   }
   //iterate and find the X and insert before it you can use prev pointer concept or just one pointer temp and check if next to next value
   Node* prev = nullptr;
   Node* temp = head;
   // while (temp!=nullptr)
   while(temp->next!=nullptr)
   {
      // if(temp->data==X){
      if(temp->next->data==X){
         // Node* newNode = new Node(val,temp);
         Node* newNode = new Node(val,temp->next);
         // prev->next = newNode;
         temp->next = newNode;
         break;
      }
      // prev = temp;
      temp = temp->next;
   }
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
Node* removeHead(Node *head){
   //delete the head of linkes list
   if(head==nullptr)return head;
   Node* temp = head;
   //point head to next and delete temp
   head = head->next;
   delete temp;
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
Node* deleteNodeWithValueX(Node* &head,int X){
   if(head==nullptr) return nullptr;
   if(head->data==X){
      Node* temp = head;
      head = head->next;
      delete temp;
      return head;
   }
   //in else secenario where x can be in between the LL
   //traverse the linkedlist then if the value found
   Node* temp = head;
   Node* prev = nullptr;
   while(temp!=nullptr){
      if(temp->data==X){
         prev->next = temp->next;
         delete temp;
         return head;
      }
      prev = temp;
      temp = temp->next;
   }
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
   // insertAtFirst(2,head);
   // insertAtFirst(8,head);
   // insertAtFirst(10,head);
   // insertAtFirst(11,head);
   // head = removeHead(head);
   // head = removeKthNode(head,8);
   // head = insertAtTail(head,4);
   // head = insertBeforeX(8,10,head);
   head = deleteNodeWithValueX(head,5);
   printNode(head);
    return 0;
}