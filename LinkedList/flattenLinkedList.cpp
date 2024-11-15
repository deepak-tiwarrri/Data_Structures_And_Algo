#include <bits/stdc++.h>
class Node
{
public:
   int data;
   Node *next;
   Node *child;
   Node() : data(0), next(nullptr), child(nullptr){};
   Node(int x) : data(x), next(nullptr), child(nullptr) {}
   Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
using namespace std;
Node *convert2LL(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *temp = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *newNode = new Node(arr[i]);
      temp->next = newNode;
      temp = newNode;
   }
   return head;
}
void printList(Node *head)
{
   Node *temp = head;
   while (temp)
   {
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "nullptr";
}
Node* mergeTwoList(Node* list1,Node* list2){
	Node* dummyNode = new Node(-1);
   Node* temp = dummyNode;
   while(list1 && list2){
      if(list1->data<list2->data){
         temp->child = list1;
         list1 = list1->child;
      }else{
         temp->child = list2;
         list2= list2->child;
      }
      temp->next = nullptr;
      temp = temp->child;
   }
   if(list1) temp->child = list1;
   else temp->child = list2;
	return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
   if(head==nullptr || head->next==nullptr) return head;
   Node* newHead = flattenLinkedList(head->next);
   return mergeTwoList(newHead,head);
}
int main()
{
   // code here
   int n;
   cin>>n;
   vector<vector<int>> number;
   for(int i=0;i<n;++i){
      int n1;
      cin>>n1;
      vector<int> temp(n1);
      for(int j=0;j<n1;++j){
         cin>>temp[j];
      }
      number.push_back(temp);
   }
   for (auto &it:number) {
        for (auto &num :it) {
            cout << num << " ";
        }
        cout << endl;
    }

   // Node* head = convert2LL(nums);
   // head = flattenLinkedList(head);
   // printList(head);
   return 0;
}