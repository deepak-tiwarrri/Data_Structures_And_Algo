#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
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

   int ans = 0;
   for (auto &it : nums)
   {
      ans = ans ^ it;
   }
   return ans;
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
   int res = singleNumber(nums);
   cout << res << endl;
   return 0;
}