#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data1,Node* next1,Node* next2){
        data = data1;
        next = next1;
        prev = next2;
    }
};
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();++i){
        Node* newNode = new Node(arr[i],nullptr,prev);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}
Node* deleteHead(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    //if head has element then in that cause
    //make a pointer prev and use it
    Node* prev = head;
    head = head->next;
    head->prev  = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
Node* deleteKthNode(Node* head,int k){
    //edge case to keep in mind 
    // if k is large then length then return head
    // if prev is null then u are on head and if nextNode is null
    // it means u are on tail 
    // if prev and nextNode both are not null then u are on middle
    // points thenode
    if(head==nullptr) return nullptr;
    
    //traverse ll and find the kth node first
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    if(temp==nullptr) return nullptr;
    if(prevNode==nullptr && nextNode==nullptr){
        // delete temp;
        return nullptr;
    }else if(prevNode==nullptr){
        //it means u are on head
        ///call delete head
        // make head to nextNode
        head = nextNode;
        nextNode->prev = nullptr;
        // delete temp;
    }else if(nextNode==nullptr){
        //delete tail
        prevNode->next = nullptr;
        temp->prev = nullptr;
        // delete temp;
    }else{
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    delete temp;
    return head;

}
Node* deleteTail(Node* &head){
    //two edge case tail is empty or tail has single element
    if(head==nullptr || head->next==nullptr) return nullptr;
    //else find the tail
    Node* tail = head;
    while(tail->next!=nullptr){
        tail =tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}
void printDLL(Node* &head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"nullptr"<<endl;
}
int main(){
  
  //code here
    int n;
  cin >> n;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans.push_back(x);
  }
  Node *head = convertArr2DLL(ans);
  //   head = reverseDLL(head);
  // head = oddEvenList(head);
  // head = sort012List(head);
    // head = deleteHead(head);
    // head = deleteTail(head);
    head = deleteKthNode(head,6);
  printDLL(head);
  return 0;
}