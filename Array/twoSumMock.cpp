#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
   //brute force approach
   //  vector<int> ans;
   //      int n = nums.size();
   //      for(int i=0;i<n;i++){
   //          for(int j=i+1;j<n;j++){
   //              if(nums[i]+nums[j]==target){
   //                  return {i,j};
   //              }
   //          }
   //      }
   //      return {-1,-1};

   //beter approach
   unordered_map<int,int> mpp;
   for(int i=0;i<nums.size();i++){
      int sub = target- nums[i];
      if(mpp.find(sub)!=mpp.end()){
         return {i,mpp[sub]};
      }
      mpp[nums[i]] = i;
   }
   return {-1,-1}; 
}
int main()
{
   // code here
   int n,target;
   cin>>n>>target;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin>>x;
      nums.push_back(x);
   }
   vector<int> res = twoSum(nums,target);
   for(auto &it:res) cout<<it<<" ";
   
   return 0;
}