#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // now put all the sea side columns and row into the queue
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    // it it is edge boundary push into the que and find the
                    // connected node then
                    if (grid[i][j] == 1) {
                        que.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        // now u have push the values into the queu and marked that row and
        // column to visited
        //  to find the connected ones u have to visit all four direction
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                // if it is not visited and grid of that row and col is 1 that
                // means they are connected
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    visited[nRow][nCol] == 0 && grid[nRow][nCol] == 1) {
                    que.push({nRow, nCol});
                    visited[nRow][nCol] = 1;
                }
            }
        }
        // now find the count how many are not visited and they are ones
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    // if grid is ones and they not have been visited than
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    // code here
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    Solution sol;
    int result = sol.numberOfEnclaves(matrix);
    cout<<"enclaves present: "<<result<<endl;

    return 0;
}