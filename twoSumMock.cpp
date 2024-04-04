#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
   // vector<int> ans;
   sort(nums.begin(),nums.end());
   int left=0,right=nums.size()-1;
   while(left<=right){
      if(nums[left]+nums[right]==target){
         return {left,right};
      }else if(nums[left]+nums[right]<target) left++;
      else right--;
   }
   return
}
int main()
{
   // code here
   vector<int> value = {2,7,11,15};
   vector<int> ans = twoSum(value,9);
   for(auto &ele:ans){
      cout<<ele<<" ";
   }
   return 0;
}