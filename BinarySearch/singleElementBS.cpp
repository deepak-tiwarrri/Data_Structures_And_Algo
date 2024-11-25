#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
   int n = nums.size();
   if (n == 1)
      return nums[0]; // edge case
   if (nums[0] != nums[1])
      return nums[0];
   if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];

   int low = 1, high = n - 2;
   //(even,odd) if we are on odd and even is same move to right
   //(odd,even) if(we are on even and odd is same) move to left half
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      // base condition
      if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
         return nums[mid];
      // it means mid is odd index
      if (mid % 2 == 1)
      {
         if (nums[mid] == nums[mid - 1])
            low = mid + 1;
         else
            high = mid - 1;
      }
      else
      {
         // it means mid is on even index
         if (nums[mid] == nums[mid - 1])
         {
            // if we are on even and odd is same move to left half
            high = mid - 1;
         }
         else
         {
            low = mid + 1;
         }
      }
   }
   return -1;
   // brutte force approach
   //  for (int i = 0; i < nums.size(); i++)
   //  {
   //     if (i == 0)
   //     {
   //        if (nums[i] != nums[i + 1])
   //           return nums[i];
   //     }
   //     else if (i == (n - 1))
   //     {
   //        if (nums[i] != nums[i - 1])
   //           return nums[i];
   //     }
   //     else
   //     {
   //        if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
   //           return nums[i];
   //     }
   //  }
   //  return -1;
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
   int res = singleNonDuplicate(nums);
   cout << res << endl;

   return 0;
}