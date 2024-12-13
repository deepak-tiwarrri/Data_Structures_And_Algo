#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(vector<int> &nums)
{
   vector<vector<int>> ans;
   int n = nums.size();
   int subset = 1 << n; // 2^n;
   for (int num = 0; num < subset; num++)
   {
      // now go to each i number
      vector<int> ansSubset;

      for (int i = 0; i < n; i++)
      {
         if ((num & (1 << i)))
         {
            // if that bit is set then
            ansSubset.push_back(nums[i]);
         }
      }
      ans.push_back(ansSubset);
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
   vector<vector<int>> res = powerSet(nums);
   for (auto &it : res)
   {
      for (auto &ele : it)
      {
         cout << ele << " ";
      }
      cout << endl;
   }

   return 0;
}