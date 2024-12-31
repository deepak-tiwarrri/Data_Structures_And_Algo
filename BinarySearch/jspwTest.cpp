// find the median element in 2d matrix when each row is sorted
#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x)
{
   int low = 0, high = arr.size() - 1;
   int ans = arr.size();
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (arr[mid] > x)
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

int countLessEqual(int val, vector<vector<int>> &matrix, int n, int m)
{
   int count = 0;
   for (int i = 0; i < m; i++)
   {
      count += upperBound(matrix[i], val);
   }
   return count;
}

int findMedian(vector<vector<int>> &matrix)
{
   // brute will be to push all the element in the 1D array and sort it
   // after that find using arr[n*m/2]
   // which will have n*m + n*mlog(n*m)
   int n = matrix.size(), m = matrix[0].size();
   int low = INT_MAX, high = INT_MIN;
   for (int i = 0; i < n; i++)
   {
      low = min(low, matrix[i][0]);
      high = max(high, matrix[i][m - 1]);
   }
   int req = (n * m) / 2;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      // here value is the mid only cause we are not using index instead using values of array as low and high
      if (countLessEqual(mid, matrix, n, m) <= req)
      {
         // search for most greatest
         // low will move from not finding to finding when it end
         low = mid + 1;
      }
      else
      {
         // high will be at that index in the end where element is lesser than equal to mid
         high = mid - 1;
      }
   }
   return low;
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
   int res = findMedian(matrix);
   cout << res << endl;
   return 0;
}