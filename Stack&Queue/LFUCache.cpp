#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   Node *next;
   Node *prev;
   int key, val;
   int cnt;
   Node(int _key, int _val)
   {
      key = _key;
      val = _val;
      next = nullptr;
      prev = nullptr;
      cnt = 1;
   }
};

class List
{
public:
   int size;
   Node *head;
   Node *tail;
   List()
   {
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head->next = tail;
      tail->prev = head;
      size = 0; // represent list size which is very crucial
   }
   void addNode(Node *newNode)
   {
      Node *temp = head->next;
      newNode->next = temp;
      newNode->prev = head;
      temp->prev = newNode;
      head->next = newNode;
      // after adding the node increase the size
      size++;
   }
   void deleteNode(Node *nodeDeleted)
   {
      Node *delPrev = nodeDeleted->prev;
      Node *delNext = nodeDeleted->next;
      delPrev->next = delNext;
      delNext->prev = delPrev;
      // after deletion decrease the size
      size--;
   }
};
class LFUCache
{
public:
   int maxCacheSize; // maximum size of cache
   int minFreq;      // minfreq till now
   int currSize;
   unordered_map<int, List *> freqListMap;
   unordered_map<int, Node *> keyNodeMap;
   LFUCache(int capacity)
   {
      maxCacheSize = capacity;
      currSize = 0;
      minFreq = 0;
   }
   void updateFreqListMap(Node *node)
   {
      keyNodeMap.erase(node->key);
      freqListMap[node->cnt]->deleteNode(node);
      if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
      {
         minFreq++;
      }
      List *nextFreqList = new List();
      if (freqListMap.find(node->cnt + 1) != freqListMap.end())
      {
         nextFreqList = freqListMap[node->cnt + 1];
      }
      node->cnt += 1;
      nextFreqList->addNode(node);
      freqListMap[node->cnt] = nextFreqList;
      keyNodeMap[node->key] = node;
   }
   int get(int key)
   {
      if (keyNodeMap.find(key) != keyNodeMap.end())
      {
         Node *temp = keyNodeMap[key];
         updateFreqListMap(temp);
         return temp->val;
      }
      return -1;
   }
   void put(int key, int value)
   {
      // first check if it is there in the map of key node
      if (maxCacheSize == 0)
         return;
      if (keyNodeMap.find(key) != keyNodeMap.end())
      {
         Node *temp = keyNodeMap[key];
         temp->val = value;
         updateFreqListMap(temp);
      }
      else
      {
         // if element not found
         if (currSize == maxCacheSize)
         {
            List *list = freqListMap[minFreq];
            keyNodeMap.erase(list->tail->prev->key);
            freqListMap[minFreq]->deleteNode(list->tail->prev);
            currSize--;
         }
         currSize++;
         minFreq = 1;
         List *listFreq = new List();
         if (freqListMap.find(minFreq) != freqListMap.end())
         {
            listFreq = freqListMap[minFreq];
         }
         Node *newNode = new Node(key, value);
         listFreq->addNode(newNode);
         freqListMap[minFreq] = listFreq;
         keyNodeMap[key] = newNode;
      }
   }
};
int main()
{
   int capacity = 2;
   LFUCache *obj = new LFUCache(capacity);
   // int param_1 = obj->get(3);
   // cout<<param_1<<endl;

   obj->put(3, 1);
   obj->put(2, 1);
   obj->put(2, 2);
   obj->put(4, 4);
   int param_1 = obj->get(2);
   cout << param_1 << endl;
}