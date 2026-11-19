#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> dijkstra(int V, const vector<vector<int>>& edges, int S) {
       
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(V,1e9);
        distance[S]= 0;
        pq.push({0,S});
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(edgeWeight+weight<distance[adjNode]){
                    distance[adjNode] = weight+ edgeWeight;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }
        return distance;

        
    }
};
int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int S;
    cin >> S;

    Solution sol;
    vector<int> distances = sol.dijkstra(V, edges, S);
    for (int i = 0; i < V; ++i) {
        if (i > 0) cout << ' ';
        if (distances[i] == INT_MAX) cout << -1;
        else cout << distances[i];
    }
    cout << '\n';

    return 0;
}
