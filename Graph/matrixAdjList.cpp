#include <bits/stdc++.h>
using namespace std;
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   // graph here
   // store in adjustancy matrix
   int adj[n + 1][n + 1]= {0};
   for (int i = 0; i < m; i++)
   {
      int u, v;
      cin >> u >> v;
      adj[u][v] = 1;
      adj[v][u] = 1;
   }
   for (int i = 1; i <= n; i++)
   //now we are moving from 1 to n and code is fixed now
   {
      for (int j = 1; j <=n; j++)
      {
         cout << adj[i][j] << " ";
      }
      cout << endl;
   }
   // cout << "hello world" << endl;

   return 0;
}