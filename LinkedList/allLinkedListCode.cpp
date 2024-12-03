// write the code to check if the given linkedlist is palindrome or not
//  write the code for it in cpp

#include <bits/stdc++.h>
class Node
{
public:
  int data;
  Node *next;

public:
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
};

using namespace std;
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
Node *reverseLL(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;
  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}
bool isPalindrome(Node *head)
{
  // Node* temp = head;
  // stack<int> s;
  // while(temp!=nullptr){
  //    s.push(temp->data);
  //    temp = temp->next;
  // }
  // temp = head;
  // while(temp!=nullptr){
  //    int top = s.top();
  //    s.pop();
  //    if(top!=temp->data){
  //       return false;
  //    }
  //    temp = temp->next;
  // }
  // return true;

  // optimal approach TC:O(2N) +O(n/2)
  //! space complexity is O(1)

  if (head->next == nullptr || head == nullptr)
    return true;
  // find the middle node
  Node *slow = head;
  Node *fast = head;
  while (fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *first = head;
  Node *newHead = reverseLL(slow->next);
  Node *second = newHead;
  while (second != nullptr)
  {
    if (first->data != second->data)
    {
      reverseLL(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
  reverseLL(newHead);
  return true;
}
Node *findMiddle(Node *head)
{
  // Write your code here
  //  Node* slow = head;
  //  Node* fast = head;
  //  while(fast && fast->next!=nullptr){
  //      fast  = fast->next->next;
  //      slow = slow->next;
  //  }
  //  return slow;
  // int n = 0;
  // Node* temp =head;
  // while(temp){
  //    n++;
  //    temp = temp->next;
  // }
  // int mid = (n/2) +1;
  // temp = head;
  // while(temp){
  //    mid--;
  //    if(mid==0) break;
  //    temp = temp->next;
  // }
  // return temp;

  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
Node *oddEvenList(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;
  Node *odd = head;
  Node *evenHead = head->next;
  Node *even = head->next;
  while (odd->next && even->next)
  {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}
int addHelper(Node *temp)
{
  if (temp == nullptr)
    return 1;
  int carry = addHelper(temp->next);
  temp->data += carry;
  if (temp->data < 10)
    return 0;
  temp->data = 0;
  return 1;
}
Node *addOneToLast(Node *head)
{
  // Write Your Code Here.
  int carry = addHelper(head);
  if (carry)
  {
    Node *newNode = new Node(1);
    newNode->next = head;
    head = newNode;
  }
  return head;
}
Node *deleteMiddle(Node *head)
{
  if (head->next == NULL)
  {
    delete head;
    return nullptr;
  }
  Node *slow = head;
  Node *fast = head;
  Node *prev = nullptr;
  while (fast && fast->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = slow->next;
  slow->next = nullptr;
  delete slow;
  return head;
}
Node *mergeTwoLists(Node *list1, Node *list2)
{
  //   if(list1==nullptr && list2==nullptr) return nullptr;
  //   if(list1==nullptr && list2->next==nullptr) return list2;
  //   if(list1->next==nullptr && list2==nullptr) return list1;

  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  Node *t1 = list1;
  Node *t2 = list2;
  if (t1 == nullptr)
    return t2;
  if (t2 == nullptr)
    return t1;
  while (t1 && t2)
  {
    if (t1->data < t2->data)
    {
      temp->next = t1;
      temp = t1;
      t1 = t1->next;
    }
    else
    {
      temp->next = t2;
      temp = t2;
      t2 = t2->next;
    }
  }
  if (t1)
    temp->next = t1;
  if (t2)
    temp->next = t2;
  return dummyNode->next;
}
bool detectLoop(Node *head)
{
  // Node* temp = head;
  // unordered_map<Node*,int> mpp;
  // while(temp){
  //   if(mpp.find(temp)!=mpp.end()){
  //     return true;//there is loop
  //   }
  //   mpp[temp] = 1;
  //   temp = temp->next;
  // }
  // return false;
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}
// return the node of linkedlist which has cycle in it
Node *firstNodeDetection(Node *head)
{
  // brute approach
  //  unordered_map<Node*,int> mpp;
  //  Node* temp = head;
  //  while(temp){
  //    // if(mpp.find(temp)!=mpp.end()){
  //      if(mpp.count(temp)!=0){
  //      //it means that node exist twice
  //      return temp;
  //    }
  //    mpp[temp] =1;
  //    temp=temp->next;
  //  }
  //  return nullptr;

  // optimal approach
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      slow = head;
      while (slow != fast)
      {
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}
// Node* findIntersection(Node *firstHead, Node *secondHead)
// {
//     //Write your code here
//     //brute appraoch
//     // using hashmap
//     // unordered_map<Node*,int> mpp;
//     // Node* temp = firstHead;
//     // while(temp){
//     //   mpp[temp] =1;
//     //   temp= temp->next;
//     // }
//     // temp = secondHead;
//     // while(temp){
//     //   if(mpp.find(temp)!=mpp.end()){
//     //     return temp;
//     //   }
//     //   temp = temp->next;
//     // }
//     // return nullptr;
//     //optimal approach
//     Node* temp1 = firstHead;
//     Node* temp2 = secondHead;
//     while(temp1!=temp2){
//       // if(temp1==nullptr) temp1 = secondHead;
//       // if(temp2 ==nullptr) temp2 = firstHead;
//       // temp1 = temp1->next;
//       // temp2 = temp2->next;
//       temp1 = temp1==NULL?secondHead?temp1->next;
//       temp2 = temp2==NULL?firstHead?temp2->next;
//     }
//     return temp1;
// }
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
Node *findMiddleList(Node *head)
{
  Node *slow = head;
  Node *fast = head->next->next;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
Node *findLength(Node *head)
{
  int len = 1;
  Node *temp = head;
  while (temp->next != nullptr)
  {
    len += 1;
    temp = temp->next;
  }
  // return len;
  cout << len << endl;
  return temp;
}
Node *mergeTwoList(Node *list1, Node *list2)
{
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  while (list1 && list2)
  {
    if (list1->data <= list2->data)
    {
      temp->next = list1;
      list1 = list1->next;
    }
    else
    {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  if (list1)
    temp->next = list1;
  if (list2)
    temp->next = list2;
  return dummyNode->next;
}
Node *sortList(Node *head)
{
  // Write your code here.
  //  vector<int> ans;
  //     Node* temp = head;
  //     while(temp){
  //         ans.push_back(temp->data);
  //         temp = temp->next;
  //     }
  //     sort(ans.begin(),ans.end());
  //     temp =head;
  //     int i=0;
  //     while(temp){
  //         temp->data = ans[i];
  //         i++;
  //         temp = temp->next;
  //     }
  //     return head;
  // if (head == NULL && head->next == NULL)
  //   return head;
  // Node *middle = findMiddleList(head);
  // Node *right = sortList(middle->next);
  // middle->next = nullptr;
  // Node *left = sortList(head);
  // return mergeTwoList(left, right);
}
Node *findKthNode(Node *temp, int k)
{
  k -= 1;
  while (temp && k > 0)
  {
    k--;
    temp = temp->next;
  }
  return temp;
}
// Node *reverseLL(Node *head)
// {
//   if (head == nullptr || head->next == nullptr)
//     return head;
//   Node *newHead = reverseLL(head->next);
//   Node *front = head->next;
//   front->next = head;
//   head->next = nullptr;
//   return newHead;
// }
// Node *reverseKthGroupNode(Node *head, int k)
// {
//   Node *temp = head;
//   Node *prevNode = nullptr;
//   while (temp)
//   {
//     Node *kthNode = findKthNode(temp, k);
//     Node *nextNode = kthNode->next;
//     if (kthNode == nullptr)
//       if (prevNode)
//         prevNode->next = nextNode;
//     break;

//     kthNode->next = nullptr;
//     reverseLL(temp);
//     if (temp == head)
//       head = kthNode;
//     prevNode = temp;
//     temp = nextNode;
//   }
//   return head;
// }
Node *findKthLastNode(Node *temp, int k)
{
  int cnt = 1;
  while (temp)
  {
    if (cnt == k)
      return temp;
    cnt++;
    temp = temp->next;
  }
  return temp;
}
Node *rotateKTimeLL(Node *head, int k)
{
  if (head == nullptr || k == 0)
    return head;
  int len = 1;
  Node *tail = head;
  while (tail->next != nullptr)
  {
    len += 1;
    tail = tail->next;
  }
  if (k % len == 0)
    return head;
  k %= len;
  tail->next = head;
  Node *newLastNode = findKthLastNode(head, len - k);
  head = newLastNode->next;
  newLastNode->next = nullptr;
  return head;
}
int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  // int n1, n2;
  // cin >> n1 >> n2;
  // vector<int> nums1;
  // for (int i = 0; i < n1; i++) {
  //   int x;
  //   cin >> x;
  //   nums1.push_back(x);
  // }
  // vector<int> nums2;
  // for (int i = 0; i < n2; i++) {
  //   int x;
  //   cin >> x;
  //   nums2.push_back(x);
  // }
  // Node *head1 = convert2LL(nums1);
  // Node *head2 = convert2LL(nums2);
  Node *head = convert2LL(nums);
  // head = removeKthEle(head, 15);
  bool isPalindromic = isPalindrome(head);
  if (isPalindromic)
    cout << "Palidrome" << endl;
  else
    cout << "Not Palindrom" << endl;
  // head = findMiddle(head);
  // head = oddEvenList(head);
  // head = deleteMiddle(head);
  // Node *head = mergeTwoLists(head1, head2);
  // Node* head = findIntersection(head1,head2);
  // Node *head1 = sortList(head);
  // head = reverseKthGroupNode(head, k);
  // head = rotateKTimeLL(head, k);
  // int result = findLength(head);
  // head = findLength(head);

  printList(head);
  // cout<<result;
  // printList(head);
}
