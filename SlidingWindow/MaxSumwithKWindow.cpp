//basic intro of sliding window

#include<bits/stdc++.h>
using namespace  std;
int maxSumWithKWindow(vector<int> &nums,int k){
   int l=0,r = k-1;
   int sum=0;
   int n = nums.size();
   int maxSum=0;
   while(r<n){
      l++;
      sum-=nums[l];
      r++;
      sum+=nums[r];
      maxSum = max(sum,maxSum);
   }
   return maxSum;
}
int main(){
   //code here
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      nums.push_back(x);
    }
    int res = maxSumWithKWindow(nums,k);
    cout<<res<<endl;

    return 0;
}