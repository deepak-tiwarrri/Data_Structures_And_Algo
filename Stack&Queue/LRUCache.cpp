#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int key, val;
   Node *next;
   Node *prev;
   Node(int _key, int _value)
   {
      key = _key;
      val = _value;
      next = nullptr;
      prev = nullptr;
   }
};
class LRUCache
{
public:
   int cap;
   Node *head = new Node(-1, -1);
   Node *tail = new Node(-1, -1);
   unordered_map<int, Node *> mpp;
   LRUCache(int capacity)
   {
      cap = capacity;
      head->next = tail;
      tail->prev = head;
   }
   void addNode(Node *newNode)
   {
      Node *temp = head->next;
      newNode->next = temp;
      newNode->prev = head;
      temp->prev = newNode;
      head->next = newNode;
   }
   void deleteNode(Node *nodeToDelete)
   {
      Node *delPrev = nodeToDelete->prev;
      Node *delNext = nodeToDelete->next;
      delPrev->next = delNext;
      delNext->prev = delPrev;
   }
   int get(int _key)
   {
      if (mpp.find(_key) != mpp.end())
      {
         // key is found
         Node *temp = mpp[_key];
         deleteNode(temp);
         addNode(temp);
         // change the value of address
         mpp[_key] = temp;
         return temp->val;
      }
      return -1;
   }
   void put(int _key, int _value)
   {
      // three condition
      if (mpp.find(_key) != mpp.end())
      {
         // take the node and change the value and put back
         Node *temp = mpp[_key];
         temp->val = _value;
         mpp.erase(_key);
         deleteNode(temp);
      }
      if (mpp.size() == cap)
      {
         // if the size is full delete the last node
         mpp.erase(tail->prev->key);
         deleteNode(tail->prev);
      }
      Node *temp = new Node(_key, _value);
      addNode(temp);
      mpp[_key] = temp;
   }
};
int main()
{
   // code here
   int capacity = 2;

   LRUCache *obj = new LRUCache(capacity);
   obj->put(2, 2);
   obj->put(1, 1);
   int param = obj->get(1);
   cout << param << endl;
   obj->put(3, 3);
   param = obj->get(2);
   cout << param << endl;
   obj->put(4, 4);
   param = obj->get(1);
   cout << param << endl;
   param = obj->get(2);
   cout << param << endl;
   param = obj->get(4);
   cout << param << endl;

   return 0;
}