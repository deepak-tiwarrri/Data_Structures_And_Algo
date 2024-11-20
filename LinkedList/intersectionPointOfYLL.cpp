#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *next;

public:
   Node(int data1, Node *next1)
   {
      data = data1;
      next = next1;
   }

public:
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
};
Node *convertArr2all(vector<int> &arr)
{
   Node *head = new Node(arr[0]);
   Node *temp = head;
   for (int i = 1; i < arr.size(); i++)
   {
      Node *newTemp = new Node(arr[i]);
      temp->next = newTemp;
      temp = newTemp;
   }
   return head;
}
void printNode(Node *head)
{
   Node *temp = head;
   while (temp != nullptr)
   {
      // cout<<temp->data<<"-->";
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "null";
   cout << endl;
}
Node* collisionPoint(Node* headA,Node* headB, int d){
   while(d>0){
      d--;
      headB = headB->next;
   }
   while(headA!=headB){
      headA = headA->next;
      headB = headB->next;
   }
   return headA;
}
Node *getIntersectionNode(Node *headA, Node *headB)
{
   // brute will be using to nested loop
   // Node *tempA = headA;
   // while (tempA != nullptr)
   // {
   //    Node *tempB = headB;
   //    while (tempB != nullptr)
   //    {
   //       if (tempB == tempA)
   //          return tempB;
   //       tempB = tempB->next;
   //    }
   //    tempA = tempA->next;
   // }
   // // if no intersection found return nullptr;
   // return NULL;

   //better approach is using founding the length of the ll and if l1<l2 then find the intersection point
   // using N2-N1 and move the l2 and if they are equal at some point return it
   // use can also use map data structure to store the each node and then if 
   // unordered_map<Node*,int> mpp;
   // Node* t1 = headA;
   // while(t1!=nullptr){
   //    mpp[t1] = 1;
   //    t1= t1->next;
   // }
   // Node* t2 = headB;
   // while(t2!=nullptr){
   //    if(mpp.find(t2)!=mpp.end()){
   //       return t2;
   //    }
   //    t2 = t2->next;
   // }
   // return nullptr;

   // Node* t1 = headA;
   // Node* t2 = headB;
   // int N1=0,N2=0;
   // while(t1!=nullptr){
   //    N1++;
   //    t1 = t1->next;
   // }
   // while(t2!=nullptr){
   //    N2++;
   //    t2 = t2->next;
   // }
   // if(N1<N2){
   //    //assuming first parameter is smaller one
   //    return collisionPoint(headA,headB,N2-N1);
   // }else{
   //    return collisionPoint(headB,headA,N1-N2);
   // }

   
}
int main()
{
   // code here
   // code here
   int n, m;
   cin >> n >> m;
   vector<int> arr;
   vector<int> arr2;
   for (int ele = 0; ele < n; ele++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   for (int ele = 0; ele < m; ele++)
   {
      int x;
      cin >> x;
      arr2.push_back(x);
   }

   Node *headA = convertArr2all(arr);
   // head = addOne(head);
   Node *headB = convertArr2all(arr2);

   Node *head = getIntersectionNode(headA, headB);
   printNode(head);
   return 0;
}