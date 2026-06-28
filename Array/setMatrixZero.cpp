#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
   int n = matrix.size();
   int m = matrix[0].size();

   bool firstRowZero = false;
   bool firstColZero = false;
   // go through the first row and check if any one is 0
   for (int j = 0; j < m; j++)
   {
      if (matrix[0][j] == 0)
         firstRowZero = true;
   }
   // go through the first col and checkc if any one is 0
   for (int i = 0; i < n; i++)
   {
      if (matrix[i][0] == 0)
         firstColZero = true;
   }

   // now go through the matrix but left the first row and first column value intact
   // cause if firstRow any value is zero than all the first row will be zero
   // same if the firsColumn has any zero than all it's value by default is going to be zero, so that is why we will touch first row and first column after change all the value
   for (int i = 1; i < n; i++)
   {
      for (int j = 1; j < m; j++)
      {
         if (matrix[i][j] == 0)
         {
            matrix[0][j] = 0;
            matrix[i][0] = 0;
         }
      }
   }
   for (int i = 1; i < n; i++)
   {
      for (int j = 1; j < m; j++)
      {
         if (matrix[0][j] == 0 || matrix[i][0] == 0)
         {
            matrix[i][j] = 0;
         }
      }
   }
   if (firstRowZero)
   {
      for (int j = 0; j < m; j++)
      {
         matrix[0][j] = 0;
      }
   }
   if (firstColZero)
   {
      for (int i = 0; i < n; i++)
      {
         matrix[i][0] = 0;
      }
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
   setZeros(matrix);
   for (auto &it : matrix)
   {
      for (auto &ele : it)
      {
         cout << ele << " ";
      }
      cout << endl;
   }
   return 0;
}