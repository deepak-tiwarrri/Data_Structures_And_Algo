#include <bits/stdc++.h>
using namespace std;
int singleNumberII(vector<int> &nums)
{
   // unordered_map<int, int> mpp;
   // for (auto &ele : nums)
   //    mpp[ele]++;
   // for (auto &it : mpp)
   // {
   //    if (it.second == 1)
   //       return it.first;
   // }
   // return -1;
   // int ans = 0; //TC: O(n*32) SC: O(1)
   // for (int bitIndex = 0; bitIndex < 32; bitIndex++)
   // {
   //    int count = 0;
   //    for (int i = 0; i < nums.size(); i++)
   //    {
   //       if (nums[i] & (1 << bitIndex))
   //       {
   //          count++;
   //       }
   //    }
   //    if (count % 3 == 1)
   //    {
   //       ans = ans | (1 << bitIndex);
   //    }
   // }
   // return ans;

   // more optimized code
   // sort(nums.begin(),nums.end());
   // for (int i = 1; i < nums.size(); i+=3)
   // {
   //    if (nums[i] != nums[i - 1])
   //       return nums[i - 1];
   // }
   // return nums[nums.size() - 1];

   int ones = 0, twos = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      ones = (ones ^ nums[i]) & (~twos);
      twos = (twos ^ nums[i]) & (~ones);
   }
   return ones;
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
   int res = singleNumberII(nums);
   cout << res << endl;
   return 0;
}