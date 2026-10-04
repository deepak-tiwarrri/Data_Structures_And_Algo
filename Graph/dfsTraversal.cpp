#include <bits/stdc++.h>
using namespace std;
void dfsTraversal(vector<int> &visited, vector<vector<int>> &adjList, int startNode, vector<int> &result)
{
   visited[startNode] = 1;
   result.push_back(startNode);
   for(auto &neighbor:adjList[startNode]){
      if(!visited[neighbor]){
         dfsTraversal(visited,adjList,neighbor,result);
      }
   }
}
void buildAdjList(vector<vector<int>> &edges, vector<vector<int>> &adjList)
{
   for (auto &neighbor : edges)
   {
      auto u = neighbor[0];
      auto v = neighbor[1];
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }
}
vector<int> depthOfGraph(int V, int E, vector<vector<int>> &edges)
{
   vector<int> visited(V, 0);
   vector<vector<int>> adjList(V);
   int startNode = 0;
   buildAdjList(edges, adjList);
   vector<int> connectedComponentResult;
   dfsTraversal(visited, adjList, startNode, connectedComponentResult);
   return connectedComponentResult;
}

int main()
{
   // code here
   int V, E;
   cin >> V >> E;
   vector<vector<int>> edges;
   for (int i = 0; i < E; i++)
   {
      int u, v;
      cin >> u >> v;
      edges.push_back({u, v});
   }
   vector<int> result = depthOfGraph(V, E, edges);
   for (auto &neighbor : result)
   {
      cout << neighbor << " ";
   }
   cout << endl;
   return 0;
}