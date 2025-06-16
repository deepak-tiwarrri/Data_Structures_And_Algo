#include <bits/stdc++.h>
using namespace std;
vector<int> bfsTraversal(int v, vector<int> adj[])
{
    return {2, 3, 4};
}
int main()
{

    // code here
    int v = 5;
    vector<int> adj[] = {
        {2, 3, 1},
        {0},
        {0, 4},
        {0},
        {2}};
    vector<int> bfs = bfsTraversal(v, adj);
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }

    return 0;
}