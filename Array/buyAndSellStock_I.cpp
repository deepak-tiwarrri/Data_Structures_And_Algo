#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
   int maxiProfit = INT_MIN;
   int miniPrices = INT_MAX;
   for (int i = 0; i < prices.size(); i++)
   {
      int cost = prices[i] - miniPrices;
      maxiProfit = max(maxiProfit, cost);
      miniPrices = min(miniPrices, prices[i]);
   }
   if (maxiProfit < 0)
      return 0;
   return maxiProfit;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> nums(n, 0);
   for (int i = 0; i < n; ++i)
   {
      cin >> nums[i];
   }
   int res = maximumProfit(nums);
   cout << res << endl;

   return 0;
}