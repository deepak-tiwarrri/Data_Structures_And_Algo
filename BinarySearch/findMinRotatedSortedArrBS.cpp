// find the minimum elemenet in rotated sorted array
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
   int n = nums.size();
   int low = 0, high = n - 1;
   int mini = INT_MAX;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      // further optimized
      if (nums[low] <= nums[high])
      {
         // it means we are on that mid which hasa left portion and right portion both as sorted
         mini = min(nums[low], mini);
         // it means we found the minimum cause we crossed the point of rotation
         break;
      }
      if (nums[low] <= nums[mid])
      {
         // it means we are on left half
         // take minimum on left sorted array and move to right
         mini = min(mini, nums[low]);
         low = mid + 1;
      }
      else
      {
         // it means we are on right half and it is sorted
         // take minimum front right side and move to left
         mini = min(mini, nums[mid]);
         high = mid - 1;
      }
   }
   return mini;
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
   int res = findMin(nums);
   cout << res << endl;

   return 0;
}