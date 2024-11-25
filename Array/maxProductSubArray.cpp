#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
   int prefix = 1, suffix = 1;
   int ans = INT_MIN;
   for (int i = 0; i < nums.size(); i++)
   {
      if (prefix == 0)
         prefix = 1;
      if (suffix == 0)
         suffix = 1;
      prefix = prefix * nums[i];
      suffix = suffix * nums[nums.size() - i - 1];
      ans = max(ans, max(prefix, suffix));
   }
   return ans;
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
   int res = maxProduct(nums);
   cout << res << endl;
   return 0;
}