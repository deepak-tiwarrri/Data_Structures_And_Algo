// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:
// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
   int maxArea = INT_MIN;
   // vector<int> nse = nextSmallerElement(heights);
   // vector<int> pse = prevSmallerElement(heights);
   // for(int i=0;i<heights.size();i++){
   //    maxArea = max(maxArea,(nse[i]-pse[i]-1)*heights[i]);
   // }
   // return maxArea;
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
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> height;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      height.push_back(x);
   }
   int res = largestRectangleArea(height);
   cout << res;

   return 0;
}