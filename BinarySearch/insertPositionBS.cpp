#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
   // find the element such that it will be inserted at smallest index such that element is >=target
   int n = nums.size();
   int lowerBoundIndx = n;
   int l = 0, h = n - 1;
   while (l <= h)
   {
      int mid = l + (h - l) / 2;
      if (nums[mid] >= target)
      {
         lowerBoundIndx = mid;
         h = mid - 1;
      }
      else
      {
         l = mid + 1;
      }
   }
   return lowerBoundIndx;
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
   int res = searchInsert(nums, x);
   cout << res << endl;

   return 0;
}