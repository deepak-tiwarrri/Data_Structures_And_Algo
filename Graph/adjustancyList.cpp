#include <bits/stdc++.h>
using namespace std;
int main()
{
   // code here

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjList(n+1);
   //  vector<vector<pair<int,int>> adjList(n+1) for weighted graph
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    for(auto &ele:adjList){
      for(auto &it:ele){
         cout<<it<<" ";
      }
      cout<<endl;
    }
   
   return 0;
} 
