#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfsTraversal(vector<vector<int>>& image, int sr, int sc, int color,
                      vector<vector<int>>& resultMatrix,int initialColor) {
        resultMatrix[sr][sc] = color;
        queue<pair<int, int>> que;
        que.push({sr, sc});
        int n = image.size();
        int m = image[0].size();
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    resultMatrix[nRow][nCol] != color && image[nRow][nCol]==initialColor) {
                    resultMatrix[nRow][nCol] = color;
                    que.push({nRow, nCol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // vector<vector<int>> visitedMatrix;
        vector<vector<int>> resultMatrix = image;
        int initialColor = image[sr][sc];
        if(initialColor==color) return image;
        bfsTraversal(image, sr, sc, color, resultMatrix,initialColor);
        return resultMatrix;
    }
};
int main() {
    // code here
    

    return 0;
}