#include <bits/stdc++.h>
using namespace std;
class Solution{
    private:
    void dfsTraversal(vector<vector<char>> &grid,vector<vector<char>> &markingMatrix,int n, int m,int row, int col){
        markingMatrix[row][col] = '1';
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                int nRow = row + i;
                int nCol = col + j;
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m  && grid[nRow][nCol]=='1' && markingMatrix[nRow][nCol]!='1'){
                    dfsTraversal(grid,markingMatrix,n,m,nRow,nCol);
                }
            }
        }
    }
    public:
    int numIslands(vector<vector<char>> & grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<char>> markingMatrix(n,vector<char>(m,'0'));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && markingMatrix[i][j]!='1'){
                    dfsTraversal(grid,markingMatrix,n,m,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main() {
    // code here
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    Solution sol;
    int result = sol.numIslands(grid);
    cout<<" no of island: "<<result<< endl;
    

    return 0;
}