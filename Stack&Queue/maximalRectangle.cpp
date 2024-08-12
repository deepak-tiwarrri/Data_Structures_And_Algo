// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:
// Input: matrix = [["0"]]
// Output: 0
// Example 3:
// Input: matrix = [["1"]]
// Output: 1
// Constraints:
// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> preSumMatrix(vector<vector<char>> &matrix)
{
   int rows = matrix.size();
   int cols = matrix[0].size();
   vector<vector<int>> preSum(rows,vector<int>(cols));
   for (int j = 0; j < cols; j++)
   {
      int sum = 0;
      for (int i = 0; i < rows; i++)
      {
         if (matrix[i][j] == '0')
            sum = 0;
         else {
            sum+=1;
            preSum[i][j] = sum;
         }
      }
   }
   return preSum;
}
int largestRectangleArea(vector<int> &heights)
{
   int maxArea = INT_MIN;
   int n = heights.size();
   stack<int> st;
   for (int i = 0; i < heights.size(); i++)
   {
      while (!st.empty() && heights[st.top()] >= heights[i])
      {
         // we know now that this element will have heights[i] has next
         // smaller element
         //  and stack value after this element is the previous smaller
         //  element of it
         int element = heights[st.top()];
         st.pop();
         int nse = i;
         int pse = st.empty() ? -1 : st.top();
         int area = element * (nse - pse - 1);
         maxArea = max(maxArea, area);
      }
      st.push(i);
   }
   while (!st.empty())
   {
      int element = heights[st.top()];
      st.pop();
      int nse = n;
      int pse = st.empty() ? -1 : st.top();
      int area = element * (nse - pse - 1);
      maxArea = max(maxArea, area);
   }
   return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
   if(matrix.empty() || matrix[0].empty()) return 0;

   vector<vector<int>> preSum = preSumMatrix(matrix);
   int maxSumRectangle = 0;
   for(int i=0;i<preSum.size();i++){
      maxSumRectangle = max(largestRectangleArea(preSum[i]),maxSumRectangle);
   }
   return maxSumRectangle;
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   vector<vector<char>> matrix(n,vector<char>(m));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         char x;
         cin >> x;
         matrix[i][j] = x;
      }
   }
   int res = maximalRectangle(matrix);
   cout << res << endl;
   return 0;
}