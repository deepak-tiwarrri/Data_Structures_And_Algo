
#include <bits/stdc++.h>
class Node {
public:
  int data;
  Node *next;
  Node *prev;

public:
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    prev = back1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
    prev = nullptr;
  }
};
using namespace std;
Node *convertArr2DLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *newNode = new Node(arr[i], nullptr, prev);
    prev->next = newNode;
    prev = newNode;
  }
  return head;
}
Node *reverseDLL(Node *head) {
  Node *curr = head;
  Node *prev = nullptr;
  while (curr != NULL) {
    prev = curr->prev;
    curr->prev = curr->next;
    curr->next = prev;
    curr = curr->prev;
  }
  return prev->prev;
}

Node *oddEvenList(Node *head) {

  //! brute force approach using TC: O(n) and SC:
  //   Node *temp = head;
  //   vector<int> ans;
  //   while (temp != nullptr && temp->next != nullptr) {
  //     ans.push_back(temp->data);
  //     temp = temp->next->next;
  //   }
  //   if (temp)
  //     ans.push_back(temp->data);
  //   temp = head->next;
  //   while (temp != nullptr && temp->next != nullptr) {
  //     ans.push_back(temp->data);
  //     temp = temp->next->next;
  //   }
  //   if (temp)
  //     ans.push_back(temp->data);
  //   int i = 0;
  //   temp = head;
  //   while (temp != nullptr) {
  //     temp->data = ans[i];
  //     i++;
  //     temp = temp->next;
  //   }
  //   return head;

  if (head == nullptr || head->next->next)
    return head;
  Node *odd = head;
  Node *even = head->next;
  Node *evenHead = head->next;
  while (even != nullptr && even->next != nullptr) {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}
Node *sort012List(Node *head) {
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  Node *temp = head;
  while (temp != nullptr) {
    if (temp->data == 0)
      cnt0++;
    else if (temp->data == 1)
      cnt1++;
    else if (temp->data == 2)
      cnt2++;
    temp = temp->next;
  }
  temp = head;
  while (temp != nullptr) {
    if (cnt0) {
      temp->data = 0;
      temp = temp->next;
      cnt0--;
    } else if (cnt1) {
      temp->data = 1;
      temp = temp->next;
      cnt1--;
    } else {
      temp->data = 2;
      temp = temp->next;
      cnt2--;
    }
    temp = temp->next;
  }
  return head;
}

void printDLL(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
Node *removeDuplicatesSortedDLL(Node *head) {
  Node *temp = head;
  while (temp && temp->next) {
    Node *nextNode = temp->next;
    while (nextNode != nullptr && temp->data == nextNode->data) {
      Node *duplicate = nextNode;
      nextNode = nextNode->next;
      delete duplicate;
    }
    temp->next = nextNode;
    if (nextNode)
      nextNode->prev = temp;
    temp = temp->next;
  }
  return head;
}
int main() {

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
  
  printDLL(head);
  return 0;
}
