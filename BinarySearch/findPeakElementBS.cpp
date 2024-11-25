#include <bits/stdc++.h>
using namespace std;
//[1,2,3,4,8,3,2,1] 8 is peak -8[....]+8 where 8 is infinity
// return the index of the peak
int findPeakElement(vector<int> &nums)
{
   // int n = nums.size();
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    if (((i == 0) || nums[i] > nums[i - 1]) && ( (i == n - 1) || nums[i] > nums[i + 1]))
   //       return i;
   // }
   // return -1;
   int n = nums.size();
   if (nums.size() == 1)
      return 0;
   if (nums[0] > nums[1])
      return 0;
   if (nums[n - 1] > nums[n - 2])
      return n - 1;

   int low = 1, high = n - 2;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if ((nums[mid] > nums[mid + 1]) && (nums[mid] > nums[mid - 1]))
         return mid;
      else if (nums[mid] < nums[mid + 1] && (nums[mid] > nums[mid - 1]))
         low = mid + 1;
      else
         high = mid - 1;
   }
   return -1;
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
   int res = findPeakElement(nums);
   cout << res << endl;

   return 0;
}