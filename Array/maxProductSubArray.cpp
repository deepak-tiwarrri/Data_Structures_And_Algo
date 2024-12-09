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

   // int maxProduct = INT_MIN;
   // int n = nums.size();
   // int prefixProduct = 1;
   // int suffixProduct = 1;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    if (prefixProduct == 0)
   //       prefixProduct = 1;
   //    if (suffixProduct == 0)
   //       suffixProduct = 1;
   //    prefixProduct = prefixProduct * nums[i];
   //    suffixProduct = suffixProduct * nums[n - i - 1];
   //    maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));
   // }
   // return maxProduct;
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