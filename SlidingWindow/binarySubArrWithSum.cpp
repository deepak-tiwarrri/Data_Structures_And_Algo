#include <bits/stdc++.h>
using namespace std;
int atMostEqualGoal(vector<int> &nums, int goal)
{
   int n = nums.size();
   if (goal < 0)
      // always check if goal is less than 0 then return count as 0
      return 0;
   int r = 0, l = 0, count = 0, sum = 0;
   while (r < n)
   {
      sum += nums[r];
      while (sum > goal)
      {
         sum -= nums[l];
         l++;
      }
      // if(sum<=goal){
      //    count = count + (r-l+1);
      // }
      count += (r - l + 1);
      r++;
   }
   return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
   // your code goes here
   // int count=0;
   //     for(int i=0;i<nums.size();++i){
   //         int sum = 0;
   //         for(int j=i;j<nums.size();++j){
   //             sum+= nums[j];
   //             if(sum>goal) break;
   //             if(sum==goal){
   //                 count = count+1;
   //             }
   //         }
   //     }
   //     return count;
   return atMostEqualGoal(nums, goal) - atMostEqualGoal(nums, goal - 1);
}
int main()
{
   // code here
   int n, goal;
   cin >> n >> goal;
   vector<int> nums(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> nums[i];
   }
   int result = numSubarraysWithSum(nums, goal);
   cout << result;
   return 0;
}