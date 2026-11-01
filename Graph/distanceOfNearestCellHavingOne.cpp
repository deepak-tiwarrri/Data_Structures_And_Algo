// Given a binary grid of N x M. 
// Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1 - i2| + |j1 - j2|,
//  where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
// Example 1:
// Input: grid = [ [0, 1, 1, 0], [1, 1, 0, 0], [0, 0, 1, 1] ]
// Output: [ [1, 0, 0, 1], [0, 0, 1, 1], [1, 1, 0, 0] ]
// Explanation: 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1),(0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

// Example 2:
// Input: grid = [ [1, 0, 1], [1, 1, 0], [1, 0, 0] ]
// Output: [ [0, 1, 0], [0, 0, 1], [0, 1, 2] ]
// Explanation: 0's at (0,1), (1,2), (2,1) and (2,2) are at a distance of 1, 1, 1 and 2 from 1's at (0,0),(0,2), (2,0) and (1,1) respectively.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> visited(N,vector<int>(M,0));
        vector<vector<int>> distanceGrid = grid;
        queue<pair<pair<int,int>,int>> que;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1){
                    que.push({{i,j},0});    
                    visited[i][j] = 1;
                }
            }
        }
        while(!que.empty()){
            auto [cordinate,dist] = que.front();
            que.pop();
            auto row = cordinate.first;
            auto col = cordinate.second;
            distanceGrid[row][col] = dist;
            vector<int> delRow = {-1,0,+1,0};
            vector<int> delCol = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newRow = delRow[i]+ row;
                int newCol = delCol[i] + col;
                if(newRow>=0 && newRow<N && newCol>=0 && newCol<M && visited[newRow][newCol]!=1){
                    que.push({{newRow,newCol},dist+1});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return distanceGrid;
    }
};
int main() {
    // code here
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    Solution sol;
    vector<vector<int>> result = sol.nearest(grid);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}