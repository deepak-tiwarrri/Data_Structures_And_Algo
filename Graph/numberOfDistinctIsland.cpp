// Problem statement
// You have been given a non-empty grid consisting of only 0s and 1s. You have to find the number of islands in the given grid.

// An island is a group of 1s (representing land) connected horizontally, vertically or diagonally. You can assume that all four edges of the grid are surrounded by 0s (representing water).

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 100
// 1 <= M <= 100
// 0 <= grid[i][j] <= 1

// Time limit: 1 sec
// Sample Input 1:
// 2
// 4 5
// 0 0 1 1 0
// 1 0 1 1 0
// 0 1 0 0 0 
// 0 0 0 0 1
// 1 3
// 1 1 1
// Sample output 1:
// 2
// 1

#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
void dfsTraversal(vector<vector<int>> &grid,vector<vector<int>> &visited,int n,int m, int &row, int &col){

    visited[row][col] = 1;
    for(int i=-1;i<=1;++i){
        for(int j=-1;j<=1;++j){
            int nRow = row + i;
            int nCol = col + j;
            //first it should be in valid nRow and nCol
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && !visited[nRow][nCol]){
                dfsTraversal(grid,visited,n,m,nRow,nCol);
            }
        }
    }
}
int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here
    vector<vector<int>> visited(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                dfsTraversal(grid,visited,n,m,i,j);
                cnt+=1;
            }
            
        }
    }
    return cnt;
}

int main() {
    // code here
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int res = numberOfIslands(grid,n,m);
    cout<<res<<" "<<endl;

    return 0;
}