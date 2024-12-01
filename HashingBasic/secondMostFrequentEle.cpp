#include <bits/stdc++.h>
using namespace std;
int secondMostFrequentElement(vector<int> &nums)
{
   // // brute force approach
   // int maxFreq = 0, secMaxFreq = 0;
   // int maxEle = -1, secMaxEle = -1;
   // int visited[10001] = {0};

   // for (int i = 0; i < nums.size(); ++i)
   // {
   //    if (visited[nums[i]] == 0)
   //    {
   //       visited[nums[i]] == 1;
   //       int cnt = 0;
   //       for (int j = 0; j < nums.size(); j++)
   //       {
   //          if (nums[j] == nums[i])
   //          {
   //             cnt++;
   //          }
   //       }
   //       if (cnt > maxFreq)
   //       {
   //          secMaxFreq = maxFreq;
   //          maxFreq = cnt;
   //          secMaxEle = maxEle;
   //          maxEle = nums[i];
   //       }
   //       else if (cnt == maxFreq)
   //       {
   //          maxEle = min(maxEle, nums[i]);
   //       }
   //       else if (cnt > secMaxFreq)
   //       {
   //          secMaxFreq = cnt;
   //          secMaxEle = nums[i];
   //       }
   //       else if (cnt == secMaxFreq)
   //       {
   //          secMaxEle = min(secMaxEle, nums[i]);
   //       }
   //    }
   // }
   //    return secMaxEle;

   // optimal approach
   unordered_map<int, int> mpp;
   int n = nums.size();
   for (auto &it : nums)
      mpp[it]++;
   int maxFreq = 0, secMaxFreq = 0;
   int maxEle = -1, secMaxEle = -1;
   for (auto &it : mpp)
   {
      int freq = it.second;
      int ele = it.first;
      if (freq > maxFreq)
      {
         secMaxFreq = maxFreq;
         maxFreq = freq;
         secMaxEle = maxEle;
         maxEle = ele;
      }
      else if (freq == maxFreq)
      {
         maxEle = min(maxEle, ele);
      }
      else if (freq > secMaxFreq)
      {
         secMaxFreq = freq;
         secMaxEle = ele;
      }
      else if (freq == secMaxFreq)
      {
         secMaxEle = min(secMaxEle, ele);
      }
   }
   return secMaxEle;
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
   int res = secondMostFrequentElement(nums);
   cout << res;

   return 0;
}