#include <bits/stdc++.h>
using namespace std;
class Solution{
    private:
        void dfs(int node,stack<int> &st,vector<vector<pair<int,int>>> &adj,int N,vector<int> &visited){
            visited[node] =1;
            for(auto &it:adj[node]){
                int nextNode = it.first;
                if(!visited[nextNode]){
                    dfs(nextNode,st,adj,N,visited);
                }
            }
            st.push(node);
        }
    public:
            vector<int> shortestPath(int N,int M,vector<vector<int>> &edges){
                //adjlist
                vector<vector<pair<int,int>> > adj(N);
                vector<int> visited(N,0);
                const int INF = INT_MAX;
                vector<int> distance(N,INF);
                for(int i=0;i<M;++i){
                    int u = edges[i][0];
                    int v = edges[i][1];
                    int w = edges[i][2];
                    adj[u].push_back({v,w});
                }
                stack<int> st;
                for(int i=0;i<N;i++){
                    if(!visited[i])
                    {
                        dfs(i,st,adj,N,visited);
                    }
                }
                distance[0] = 0;
                while(!st.empty()){
                    auto node = st.top();
                    st.pop();
                    if(distance[node]!=INF){
                        for(auto &it:adj[node]){
                        int adjNode = it.first;
                        int edgeWeight = it.second;
                        if(edgeWeight+distance[node]<distance[adjNode]){
                            distance[adjNode] = edgeWeight+distance[node];
                        }
                    }
                    }
                }
                for(int i=0;i<N;i++){
                    if(distance[i]==INF){
                        distance[i] = -1;
                    }
                }
                return distance;
                
            }
};
int main() {
    int V,M;
    if(!(cin>>V>>M)){
        cerr<<"Error: expected vertices and edges counts\n";
        return 1;
    }
    if(V<0 || M<0){
        cerr<<"Error: vertices and edges counts must be non-negative\n";
        return 1;
    }
    vector<vector<int>> edges;
    for(int i=0;i<M;i++){
        vector<int> edge;
        for(int i=0;i<3;++i){
            int x;
            if(!(cin>>x)){
                cerr<<"Error: edge "<<i+1<<" is incomplete\n";
                return 1;
            }
            edge.push_back(x);
        }
        int u = edge[0];
        int v = edge[1];
        if(u<0 || u>=V || v<0 || v>=V){
            cerr<<"Error: edge "<<i+1<<" contains a vertex outside 0.."<<V-1<<"\n";
            return 1;
        }
        edges.push_back(edge);
    }

    Solution sol;
    vector<int> result = sol.shortestPath(V,M,edges);
    for(int i=0;i<(int)result.size();++i){
        if(i) cout<<" ";
        cout<<result[i];
    }
    cout<<"\n";

    return 0;
}