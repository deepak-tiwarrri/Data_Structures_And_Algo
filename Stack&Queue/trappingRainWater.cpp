// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <bits/stdc++.h>
using namespace std;
vector<int> preMax(vector<int> &height)
{
   vector<int> prefixMax(height.size());
   prefixMax[0] = height[0];
   for (int i = 1; i < height.size(); i++)
   {
      prefixMax[i] = max(prefixMax[i - 1], height[i]);
   }
   return prefixMax;
}
vector<int> suffMax(vector<int> &height)
{
   vector<int> suffixMax(height.size());
   suffixMax[height.size() - 1] = height[height.size() - 1];
   for (int i = height.size() - 2; i >= 0; i--)
   {
      suffixMax[i] = max(suffixMax[i + 1], height[i]);
   }
   return suffixMax;
}

int trap(vector<int> &height)
{
   // int total = 0;
   // vector<int> suffixMax = suffMax(height);
   // vector<int> prefixMax = preMax(height);
   // for (int i = 0; i < height.size(); i++)
   // {
   //    total = total + (min(suffixMax[i], prefixMax[i]) - height[i]);
   // }
   // return total;

   // optimal approach is we have to find the left smaller and if it is supported by the right greater than we can find the total

   int l = 0, r = height.size()-1, rightMax = INT_MIN, leftMax = INT_MIN;
   int total = 0;
   while (l < r)
   {
      if (height[l] <= height[r])
      {
         if (leftMax > height[l])
            total = total + (leftMax - height[l]);
         else
            leftMax = height[l];
         l++;
      }
      else
      {
         if (rightMax > height[r])
            total = total + (rightMax - height[r]);
         else
            rightMax = height[r];
         r--;
      }
   }
   return total;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   int res = trap(arr);
   cout << res << endl;

   return 0;
}