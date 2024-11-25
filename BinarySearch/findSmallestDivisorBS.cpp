#include <bits/stdc++.h>
using namespace std;
int findDivisorSum(int val, vector<int> &nums)
{
   int n = nums.size();
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += ceil((double)(nums[i]) / (double)(val));
   }

   return sum;
}
int smallestDivisor(vector<int> &nums, int limit)
{
   // brute force TC: maxele*N
   //  for (int d = 1; d <= maxElement; ++d)
   //  {
   //     int sum = 0;
   //     for (int i = 0; i < nums.size(); i++)
   //     {
   //        sum = sum + ceil(nums[i] / d);
   //     }
   //     if (sum <= limit)
   //        return d;
   //  }
   //  return -1;

   // optimal appraoch using binary search
   int maxElement = *max_element(nums.begin(), nums.end());
   int low = 1, high = maxElement;
   while (low <= high)
   {
      int mid = (high - low) / 2 + low;
      if (findDivisorSum(mid, nums) <= limit)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return low;
}
int main()
{
   // code here
   int n, limit;
   cin >> n >> limit;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = smallestDivisor(nums, limit);
   cout << res << endl;

   return 0;
}