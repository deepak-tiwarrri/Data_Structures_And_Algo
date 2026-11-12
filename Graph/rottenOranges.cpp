#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<int>> copiedGrid = grid;
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int, int>, int>> que;
        int fresh = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int maxTime = 0;
        while (!que.empty())
        {
            auto [pos, time] = que.front();
            que.pop();
            maxTime = max(time, maxTime);

            for (int i = 0; i < delRow.size(); i++)
            {
                int nRow = pos.first + delRow[i];
                int nCol = pos.second + delCol[i];
                //with the boundary and it should be fresh orange
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && copiedGrid[nRow][nCol] == 1)
                {
                    copiedGrid[nRow][nCol] = 2;
                    que.push({{nRow, nCol}, time + 1});
                    fresh--;
                }
            }
        }
        return fresh > 0 ? -1 : maxTime;
    }
};
int main()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    int result = sol.orangesRotting(grid);
    cout << "time taken: " << result << endl;

    return 0;
}