#include <bits/stdc++.h>
using namespace std;
vector<int> dfsTraversal(vector<vector<int>> &adjList, int &startNode, vector<int> &visArr, vector<int> &ans)
{
   // so for example start node is 1
   visArr[startNode] = 1;
   ans.push_back(startNode);
   for (auto &ele : adjList[startNode])
   {
      if (!visArr[ele])
      {
         dfsTraversal(adjList, ele, visArr, ans);
      }
   }
}
vector<vector<int>> buildAdjList(int &n, int &m)
{
   vector<vector<int>> ans(n);
   for (int i = 0; i < n; i++)
   {
      int u, v;
      cin >> u >> v;
      ans[v].push_back(u);
      ans[u].push_back(v);
   }
   return ans;
}

int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   vector<int> vis(n, 0);
   vector<vector<int>> adjList = buildAdjList(n, m);
   vector<int> dfsPath;
   int startNode = 1;
   vector<int> result = dfsTraversal(adjList, startNode, vis, dfsPath);
   for (auto &it : result)
   {
      cout << it << " ";
   }

   return 0;
}