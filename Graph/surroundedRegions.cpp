#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfsTraversal(vector<vector<char>> &mat, int row, int col, vector<vector<char>> &copiedMatrix, vector<vector<int>> &visited)
    {
        int N = mat.size();
        int M = mat[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        visited[row][col] = 1;
        copiedMatrix[row][col] = 'X';
        for (int i = 0; i < 4; i++)
        {
            int nRow = delRow[i] + row;
            int nCol = delCol[i] + col;
            if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < M && mat[nRow][nCol] == 'X' && visited[nRow][nCol] != 1)
            {
                copiedMatrix[nRow][nCol] = 'X';
                visited[nRow][nCol] = 1;
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>> &mat)
    {
        queue<pair<int, int>> que;
        int N = mat.size();
        int M = mat[0].size();
        vector<vector<int>> visited(N, vector<int>(M, 0));
        vector<vector<char>> copiedMatrix = mat;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((i != 0 || i != N) && (j != 0 || j != M))
                {
                    if (mat[i][j] == '0')
                    {
                        dfsTraversal(mat, i, j, copiedMatrix, visited);
                    }
                }
            }
        }
        return copiedMatrix;
    }
};
int main()
{
    // code here
    int N, M;
    cin >> N >> M;
    vector<vector<char>> mat(N, vector<char>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    vector<vector<char>> result = sol.fill(mat);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}