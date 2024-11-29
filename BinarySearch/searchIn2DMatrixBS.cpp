#include <bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> &nums, int target)
{
   int low = 0, high = nums.size() - 1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
         return true;
      else if (nums[mid] > target)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return false;
}
bool searchMatrix(vector<vector<int>> matrix, int target)
{
   // brute approach
   bool isFound = false;
   // for (int i = 0; i < matrix.size(); ++i)
   // {
   //    for (int j = 0; j < matrix[0].size(); j++)
   //    {
   //       if (matrix[i][j] == target)
   //       {
   //          return true;
   //       }
   //       else
   //          continue;
   //    }
   // }
   // return false;

   // better approach // O(n+ log(m))
   // int m = matrix[0].size();
   // for (int i = 0; i < matrix.size(); ++i)
   // {
   //    if (matrix[i][0] <= target && target <= matrix[i][m - 1])
   //    {
   //       if (binarySearch(matrix[i], target))
   //       {
   //          return true;
   //       }
   //    }
   // }
   // return false;
   int n = matrix.size();
   int m = matrix[0].size();
   int low = 0, high = n * m - 1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      int row = mid / m, col = mid % m;
      if (matrix[row][col] == target)
         return true;
      else if (matrix[row][col] < target)
         low = mid + 1;
      else
         high = mid - 1;
   }
   return false;
}
int main()
{
   // code here
   int n, m, target;
   cin >> n >> m >> target;
   vector<vector<int>> matrix(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> matrix[i][j];
      }
   }
   bool res = searchMatrix(matrix, target);
   if (res)
      cout << "true";
   else
      cout << "false";

   return 0;
}