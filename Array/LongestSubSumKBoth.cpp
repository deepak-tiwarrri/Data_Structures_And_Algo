//find the longest subarray with sum k if the array 
//contains both postives and negative

#include<bits/stdc++.h>
using namespace  std;
// int longestSubarrayWithSumK(vector<int> &nums,int k){
//    //brute force approach
//    // int maxLen = 0;
//    // int sum = 0;
//    // for(int i=0;i<nums.size();++i){
//    //    for(int j=i;j<nums.size();++j){
//    //       sum+=nums[j];
//    //       if(sum==k){
//    //          maxLen = max(maxLen,j-i+1);
//    //       }         
//    //    }
//    // }
//    // return maxLen;

//    //optimal approach for postive and negative array
//    unordered_map<int,int> preSumHash;
//    int maxLen = 0;
//    int sum = 0;
//    for (int i = 0; i < nums.size(); i++)
//    {
//       sum+=nums[i];
//       if(sum==k){
//          maxLen = max(maxLen,i+1);
//       }
//       int rem = sum-k;
//       if(preSumHash.find(rem)!=preSumHash.end()){
//          int len = i-preSumHash[rem];
//          maxLen = max(maxLen,len);
//       }
//       if(preSumHash.find(sum)==preSumHash.end()){
//          preSumHash[sum] =i;
//       }
//    }
//    return maxLen;
// }
//longest sum with k where positives elements are there
int longestSubarrayWithSumK(vector<int> &nums,int k){
   long long sum = nums[0];
   int left = 0,right = 0;
   int maxLen = 0;
   int n = nums.size();
   while(right<n){
      while(left<=right && sum>k){
         sum-=nums[left];
         left++;
      }
      if(sum==k){
         maxLen = max(maxLen,right-left+1);
      }
      right++;
      if(right<n) sum+= nums[right];
   }
   return maxLen;
}
int main(){
   //code here
   int n,k;
   cin>>n>>k;
   vector<int> nums(n,0);
   for(int i=0;i<n;++i){
      cin>>nums[i];
   }    
   int res = longestSubarrayWithSumK(nums,k);
   cout<<res<<endl;
    return 0;
}