#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeBySign(vector<int> &nums)
{
   // vector<int> pos;
   // vector<int> neg;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    if (nums[i] > 0)
   //       pos.push_back(nums[i]);
   //    else
   //       neg.push_back(nums[i]);
   // }
   // // now go to the half of the nums.size()
   // for (int i = 0; i < nums.size() / 2; i++)
   // {
   //    nums[2 * i] = pos[i];
   //    nums[2 * i + 1] = neg[i];
   // }
   // int i = 0, j = 0, k = 0;
   // while (i < pos.size() && j < neg.size())
   // {
   //    nums[k] = pos[i];
   //    k++, i++;
   //    nums[k] = neg[j];
   //    k++, j++;
   // }// TC: O(n) + O(n/2)
   // SC: O(n)

   // optimal approach
   int posIndex = 0, negIndex = 1;
   int n = nums.size();
   vector<int> ans(n, 0);
   for (auto &ele : nums)
   {
      if (ele > 0)
      {
         ans[posIndex] = ele;
         posIndex += 2;
      }
      else
      {
         ans[negIndex] = ele;
         negIndex += 2;
      }
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
   vector<int> res = rearrangeBySign(nums);
   for (auto &it : res)
   {
      cout << it << " ";
   }

   return 0;
}