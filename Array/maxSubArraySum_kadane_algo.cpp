// kadane algorithm

#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
   // brute force approach
   //  long long maxi = LLONG_MIN;
   //  for(int i=0;i<nums.size();++i){
   //     long long sum = 0;
   //     for(int j=i;j<nums.size();++j){
   //        sum+= nums[j];
   //        if(sum>maxi){
   //           maxi = sum;
   //        }
   //     }
   //  }

   long long maxi = LLONG_MIN;
   long long sum = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      sum += nums[i];
      maxi = max(sum, maxi);
      if (sum < 0)
         sum = 0;
   }
   return maxi;
}
vector<int> maxSubArraySumII(vector<int> &nums)
{
   // u have to print that subarray or store it and give it
   vector<int> result;
   long long maxi = LLONG_MIN;
   long long sum = 0;
   int start = 0;
   int endIndex = 0;
   int startIndex = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      if (sum == 0)
         start = i;
      sum += nums[i];
      if (sum > maxi)
      {
         maxi = sum;
         // end will only be that index which caused the maxi to update itself
         // when your maximum updates that will be your end index
         startIndex = start;
         endIndex = i;
      }
      if(sum<0)
         sum = 0;
   }
   cout << "startIndex: " << startIndex << endl;
   cout << "endIndex: " << endIndex << endl;
   for (int i = startIndex; i <= endIndex; i++)
   {
      result.push_back(nums[i]);
   }
   return result;
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
   // int res = maxSubArray(nums);
   vector<int> ans = maxSubArraySumII(nums);
   for (auto &it : ans)
   {
      cout << it << " ";
   }
   return 0;
}