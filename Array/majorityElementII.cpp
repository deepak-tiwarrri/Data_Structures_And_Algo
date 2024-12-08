#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &nums)
{
   // the element that appears more than n/3 times is called as majority element 2
   //  there can be any number of this element but only 2 can be possible and when it become 2 return it

   // below is the brute force approach to solve this
   // using TC: O(n^2) and sc:O(k)

   // vector<int> ansEle;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    if (ansEle.size() == 0 || ansEle[0] != nums[i])
   //    {
   //       int count = 0;
   //       for (int j = 0; j < nums.size(); j++)
   //       {
   //          if (nums[j] == nums[i])
   //          {
   //             count++;
   //          }
   //       }
   //       if (count > nums.size() / 3)
   //          ansEle.push_back(nums[i]);
   //    }
   //    if (ansEle.size() == 2)
   //       break;
   // }
   // return ansEle;

   // better approach using hashing
   //  vector<int> ans;
   //  unordered_map<int, int> mpp;
   //  for (auto &it : nums)
   //  {
   //     mpp[it]++;
   //     if (mpp[it] > nums.size() / 3)
   //        ans.push_back(it);
   //     if (ans.size() == 2)
   //        break;
   //  }
   //  return ans;

   // optimal approaching TC: O(n) ans SC: O(1)
   int cnt1 = 0, cnt2 = 0;
   int ele1 = INT_MIN, ele2 = INT_MIN;
   vector<int> ans;

   for (int i = 0; i < nums.size(); i++)
   {
      if (cnt1 == 0 && ele2 != nums[i])
      {
         ele1 = nums[i];
         cnt1 = 1;
      }
      else if (cnt2 == 0 && ele1 != nums[i])
      {
         ele2 = nums[i];
         cnt2 = 1;
      }
      else if (ele1 == nums[i])
         cnt1++;
      else if (ele2 == nums[i])
         cnt2++;
      else
      {
         cnt2--;
         cnt1--;
      }
   }
   int mini = (nums.size() / 3 + 1);
   cnt1 = 0, cnt2 = 0;
   for (auto &it : nums)
   {
      if (it == ele1)
         cnt1++;
      if (it == ele2)
         cnt2++;
   }
   if (cnt1 >= mini)
      ans.push_back(ele1);
   if (cnt2 >= mini)
      ans.push_back(ele2);
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
   vector<int> res = majorityElementII(nums);
   for (auto &it : res)
   {
      cout << it << " ";
   }

   return 0;
}