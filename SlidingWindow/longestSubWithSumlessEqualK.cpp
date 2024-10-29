//longest subarray with sum less than equal to k
#include<bits/stdc++.h>
using namespace  std;
   
int lengthSubSumLessEqualToK(vector<int> &nums,int k){
   // int maxLen = 0;
   // for(int i=0;i<nums.size();++i){
   //    int sum =0;
   //    for(int j=i;j<nums.size();j++){
   //       sum+= nums[j];
   //       if(sum<=k){
   //          maxLen = max(maxLen,j-i+1);
   //       }else{
   //          break;
   //       }
   //    }
   // }
   // return maxLen;   

   int l=0,r = 0;
   int n = nums.size();
   int sum =0;
   int maxLen = 0;
   while(r<n){
      sum = sum+ nums[r];
      // while(sum>k && l<=r){
      //    sum-=nums[l];
      //    l--;
      // }
      if(sum>k && l<=r){
         sum-=nums[l];
         l--;
      }
      if(sum<=k){
         maxLen = max(maxLen,r-l+1);
      }
      r++;
   }
   return maxLen;
}
int main(){
   //code here
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      nums.push_back(x);
    }
    int res = lengthSubSumLessEqualToK(nums,k);
    cout<<res<<endl;
    return 0;
}