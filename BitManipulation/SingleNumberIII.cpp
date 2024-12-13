#include <bits/stdc++.h>
using namespace std;
// return the single element when it is more than once
// ex: 1 1 2 2 3 4
// here: 3 and 4 are single element
vector<int> singleNumberIII(vector<int> &nums)
{
   // TC: O(N)+ O(M) m is map size
   // SC: O(m) where m is n/2+1
   //  unordered_map<int, int> mpp;
   //  vector<int> ans;
   //  for (auto &ele : nums)
   //     mpp[ele]++;
   //  for (auto &it : mpp)
   //  {
   //     if (it.second == 1)
   //     {
   //        ans.push_back(it.first);
   //     }
   //  }
   //  return ans;

   // optimal code use the concept of bit manipulation

   // first xor each element so that only
   int xOR = 0;
   for (auto &it : nums)
      xOR ^= it;

   // find the first rightmost bit and on the basis of it differentiate the bucket1 and bucket2
   int rightMost = (xOR & (xOR - 1)) ^ xOR;
   int buck1 = 0, buck2 = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      if (rightMost & nums[i])
      {
         // if it is given 1 then add it the bucket 1
         buck1 = buck1 ^ nums[i];
      }
      else
      {
         buck2 = buck2 ^ nums[i];
      }
   }
   if (buck1 < buck2)
      return {buck1, buck2};
   return {buck2, buck1};
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   vector<int> res = singleNumberIII(nums);
   for (auto &it : res)
      cout << it << " ";
   return 0;
}