#include <bits/stdc++.h>
using namespace std;
// rotate image by 90 degree
// given 2d array rotate it by 90 degree
void rotateMatrix(vector<vector<int>> &matrix)
{
   int n = matrix.size();
   int m = matrix[0].size();
   // brute force approach
   //  vector<vector<int>> ans(n, vector<int>(m, 0));
   //  for (int i = 0; i < n; i++)
   //  {
   //     for (int j = 0; j < m; j++)
   //     {
   //        ans[j][n - i - 1] = matrix[i][j];
   //     }
   //  }
   //  for (int i = 0; i < ans.size(); i++)
   //  {
   //     for (int j = 0; j < ans[0].size(); j++)
   //     {
   //        matrix[i][j] = ans[i][j];
   //     }
   //  }

   // find the tranpose and reverse the each row of the matrix
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = i + 1; j < m; j++)
      {
         swap(matrix[i][j], matrix[j][i]);
      }
   }
   // now reverse the each row
   for (int i = 0; i < n; i++)
   {
      reverse(matrix[i].begin(), matrix[i].end());
   }
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   vector<vector<int>> matrix;
   for (int i = 0; i < n; i++)
   {
      vector<int> row;
      for (int j = 0; j < m; j++)
      {
         int x;
         cin >> x;
         row.push_back(x);
      }
      matrix.push_back(row);
   }
   rotateMatrix(matrix);
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}