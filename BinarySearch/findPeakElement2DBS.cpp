#include <bits/stdc++.h>
using namespace std;
// find the peak elment in the 2D matrix the (row,col) such that it is greater than left, right ,top and bottom

int findRowMaxIndex(vector<vector<int>> &mat, int n, int m, int mid)
{
   int rowIndex = -1;
   int rowMaxValue = INT_MIN;
   // go to the col which is fixed and row is changing
   for (int i = 0; i < n; i++)
   {
      if (mat[i][mid] > rowMaxValue)
      {
         rowMaxValue = mat[i][mid];
         rowIndex = i;
      }
   }
   return rowIndex;
}
vector<int> findPeakElement(vector<vector<int>> &mat)
{
   // the brute force would be to find the maximum elment from the array and return it
   // cause it will be great from it's top, bottom, left and right
   // TC: O(n*m) SC: O(1)
   // int maxEle = INT_MIN;
   int n = mat.size(), m = mat[0].size();
   // int row = -1, col = -1;
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = 0; j < m; j++)
   //    {
   //       if (maxEle < mat[i][j])
   //       {
   //          maxEle = mat[i][j];
   //          row = i;
   //          col = j;
   //       }
   //    }
   // }
   // return {row, col};

   // now I have to find the optimal solution and we can use thhe concept of peak element in one d
   int low = 0, high = m - 1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      int rowMaxIndex = findRowMaxIndex(mat, n, m, mid);
      int left = mid - 1 >= 0 ? mat[rowMaxIndex][mid - 1] : -1;
      int right = mid + 1 < m ? mat[rowMaxIndex][mid + 1] : -1;
      if (mat[rowMaxIndex][mid] > left && mat[rowMaxIndex][mid] > right)
         return {rowMaxIndex, mid};
      else if (mat[rowMaxIndex][mid] < right)
      {
         low = mid + 1;
      }
      else
         high = mid - 1;
   }
   return {-1, -1};
}
int main()
{
   // code here

   // code here
   int n, m;
   cin >> n >> m;
   vector<vector<int>> matrix(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> matrix[i][j];
      }
   }
   vector<int> res = findPeakElement(matrix);
   for (auto &it : res)
      cout << it << " ";

   return 0;
}