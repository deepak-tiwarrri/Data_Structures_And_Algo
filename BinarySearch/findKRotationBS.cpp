// Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 1 and n. Determine the number of rotations performed on the array.

// Example 1
// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

// Output: 4

// Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &nums)
{
   // find the minimum in rotated sorted array and take that index and return it
   int low = 0, high = nums.size() - 1;
   int mini = INT_MAX;
   int minIndex = -1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (nums[low] <= nums[high])
      {
         // it means we are in rotated sorted array pointed
         // our mid is in rotated sorted array
         if (nums[low] < mini)
         {
            mini = nums[low];
            minIndex = low;
            break;
         }
      }
      if (nums[low] <= nums[mid])
      {
         // it means we are in sorted array
         if (nums[low] < mini)
         {
            mini = nums[low];
            minIndex = low;
         }
         low = mid + 1;
      }
      else
      {
         // it means we are in right half of sorted array
         if (nums[mid] < mini)
         {
            mini = nums[mid];
            minIndex = mid;
         }
         high = mid - 1;
      }
   }
   return minIndex;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = findKRotation(nums);
   cout << res << endl;

   return 0;
}