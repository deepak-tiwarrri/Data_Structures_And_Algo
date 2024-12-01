#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{
   int maxLen = 0;
   int n = nums.size();
   int sum = 0;
   unordered_map<int, int> mpp;
   for (int i = 0; i < n; i++)
   {
      sum += nums[i];
      if (sum == k)
      {
         maxLen = max(maxLen, i + 1);
      }
      int rem = sum - k;
      if (mpp.find(rem) != mpp.end())
      {
         int len = i - mpp[rem];
         maxLen = max(maxLen, len);
      }
      if (mpp.find(sum) == mpp.end())
      {
         mpp[sum] = i;
      }
   }

   return maxLen;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = longestSubarray(nums, k);
   cout << res;

   return 0;
}