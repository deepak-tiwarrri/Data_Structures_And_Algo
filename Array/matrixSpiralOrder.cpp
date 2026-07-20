#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << "matrix:" << matrix[top][i];
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << "matrix:" << matrix[i][right];
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << "matrix:" << matrix[bottom][i];
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << "matrix:" << matrix[i][left];
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    cout << endl;
    return ans;
}
/*
    1 2 3  4
    5 6  7  8
    9 10 11 12
    13 14 15 16
*/
int main()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> matrix;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            matrix.push_back(x);
        }
        ans.push_back(matrix);
    }
    vector<int> res = spiralOrder(ans);
    for (auto &it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}