#include <bits/stdc++.h>
using namespace std;
// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.
// Example 1
// Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0
// Output: 4
// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

int searchInRotatedSorted(vector<int> &nums, int k)
{
   // brute can be using linear search
   // and optimal can be using binary search
   // but first determine which part of sorted array you are
   // left sorted or right sorted part
   int low = 0, high = nums.size() - 1;
   while (low <= high)
   {
      // first check if it left sorted or right sorted
      int mid = low + (high - low) / 2;
      if (nums[mid] == k)
         return mid;
      else if (nums[low] <= nums[mid])
      {
         // it means you are on left sorted
         if (nums[low] <= k && k <= nums[mid])
            high = mid - 1;
         else
            low = mid + 1;
      }
      else
      {
         if (nums[mid] <= k && k <= nums[high])
            low = mid + 1;
         else
            high = mid - 1;
      }
   }
   // if not found return
   return -1;
}
bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
{
   int low = 0, high = nums.size() - 1;
   while (low <= high)
   {
      // first check if it left sorted or right sorted
      int mid = low + (high - low) / 2;
      if (nums[mid] == nums[low] && nums[mid] == nums[high])
      {
         low = low + 1;
         high = high - 1;
         continue;
      }
      if (nums[mid] == k)
         return true;
      else if (nums[low] <= nums[mid])
      {
         // it means you are on left sorted
         if (nums[low] <= k && k <= nums[mid])
            high = mid - 1;
         else
            low = mid + 1;
      }
      else
      {
         if (nums[mid] <= k && k <= nums[high])
            low = mid + 1;
         else
            high = mid - 1;
      }
   }
   // if not found return
   // return -1;
   return false;
}
int main()
{
   // code here
   int n, x;
   cin >> n >> x;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   bool res = searchInARotatedSortedArrayII(nums, x);
   cout << res << endl;

   return 0;
}