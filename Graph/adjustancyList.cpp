#include <bits/stdc++.h>
using namespace std;
int main()
{
   // code here

   int n, m;

   vector<int> adjList[n + 1];
   for (int i = 0; i < m; i++)
   {
      int u, v;
      cin >> u >> v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }

   for (auto &it : adjList)
   {
      for (int i = 0; i < it.size(); i++)
      {
         cout << it[i];
      }
   }
   return 0;
}