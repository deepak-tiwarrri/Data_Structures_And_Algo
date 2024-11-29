#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int target)
{
   int low = 0, high = arr.size() - 1;
   int ans = arr.size();
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (arr[mid] >= target)
      {
         ans = mid;
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   return ans;
}
int rowWithMax1s(vector<vector<int>> &mat)
{
   //[1,1,1] //[0,0]
   //[0,0,1] //[0,0]
   //[0,0,0]

   // int index = -1;
   // int maxRow = -1;
   // for(int i=0;i<mat.size();i++){
   //   int countRow = 0;
   //   for(int j=0;j<mat[0].size();j++){
   //      countRow += mat[i][j];
   //   }
   //   if(countRow>maxRow){
   //     maxRow = countRow;
   //     index = i;
   //   }
   // }
   // return index;
   // int cnt = 0;
   int maxCount = 0;
   int index = -1;
   int m = mat[0].size();
   for (int i = 0; i < mat.size(); i++)
   {
      int cnt = m - lowerBound(mat[i], 1);
      if (cnt > maxCount)
      {
         maxCount = cnt;
         index = i;
      }
   }
   return index;
}
int main()
{
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
   int res = rowWithMax1s(matrix);
   cout << res << endl;
   return 0;
}