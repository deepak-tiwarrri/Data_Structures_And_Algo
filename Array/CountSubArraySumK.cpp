#include <bits/stdc++.h>
using namespace std;
int subArraySumCount(vector<int> &nums, int k)
{
   // int maxCount  =0;
   // TC: O(n^2) and SC: O(1)
   // int count = 0;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    // generate subarray and calculate the count of it
   //    int sum = 0;
   //    for (int j = i; j < nums.size(); j++)
   //    {
   //       sum += nums[j];
   //       if (sum == k)
   //       {
   //          count++;
   //       }
   //    }
   // }
   // return count;

   // optimal approach is this
   // using map O(n) SC: O(1)
   //  unordered_map<int, int> countSumHash;
   //  int sum = 0;
   //  int count = 0;
   //  countSumHash[0] = 1;
   //  for (int i = 0; i < nums.size(); ++i)
   //  {
   //     sum += nums[i];
   //     countSumHash[sum] += 1;
   //     int rem = sum - k;
   //     count += countSumHash[rem];
   //  }
   //  return count;

   // now trying to do this problem using two pointer approach
   //but this approach is only valid for positives
   
   int left = 0;
   int right = 0;
   int n = nums.size();
   int sum = 0;
   int count = 0;
   while (right < n)
   {
      // traverse in the array if sum ==k increase the count
      sum += nums[right];
      while (left <= right && sum > k)
      {
         sum -= nums[left];
         left++;
      }
      if (sum == k)
      {
         count++;
      }
      right++;
   }
   return count;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> nums(n, 0);
   for (int i = 0; i < n; ++i)
   {
      cin >> nums[i];
   }
   int res = subArraySumCount(nums, k);
   cout << res << endl;

   return 0;
}