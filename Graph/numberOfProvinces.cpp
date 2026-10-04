#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfsTraversal(vector<int> &visited, vector<vector<int>> &adjList,
                      int startNode)
    {
        visited[startNode] = 1;
        // result.push_back(startNode);
        for (auto &neighbor : adjList[startNode])
        {
            if (!visited[neighbor])
            {
                dfsTraversal(visited, adjList, neighbor);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj)
    {
        int V = adj.size();
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> visited(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfsTraversal(visited, adjList, i);
            }
        }
        return cnt;
    }
};

int main()
{
    // code here
    int V;
    cin >> V;

    // Initialize a V x V matrix with 0s
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    // Read the matrix input directly
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    Solution sol;
    int result = sol.numProvinces(adjMatrix);
    cout<<result<<" result printed"<<endl;
    return 0;
}