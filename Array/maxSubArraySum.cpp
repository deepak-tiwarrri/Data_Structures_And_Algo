//kadane algorithm

#include<bits/stdc++.h>
using namespace  std;
int maxSubArray(vector<int> &nums){
   //brute force approach
   long long maxi = LLONG_MIN;
   for(int i=0;i<nums.size();++i){
      long long sum = 0;
      for(int j=i;j<nums.size();++j){
         sum+= nums[j];
         if(sum>maxi){
            maxi = sum;
         }
      }
   }
   return maxi;
}
int main(){
   //code here
   int n;
   cin>>n;
   vector<int> nums;
   for(int i=0;i<n;++i){
      int x;
      cin>>x;
      nums.push_back(x);
   }
   int res = maxSubArray(nums);
   cout<<res<<endl;

    return 0;
}