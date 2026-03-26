#include <bits/stdc++.h>
using namespace std;
int main()
{
   // code here

   int n, m;
   cin >> n >> m;
   vector<int> adjList[n + 1];
   for (int i = 0; i < m; i++)
   {
      int u, v;
      cin >> u >> v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }
   for (int i = 0; i <= sizeof(adjList) / sizeof(adjList[0]); i++)
   {
      for (auto &it : adjList[i])
      {
         cout << it << " ";
      }
      cout << endl;
   }
   return 0;
}