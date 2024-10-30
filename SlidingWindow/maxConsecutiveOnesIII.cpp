#include<bits/stdc++.h>
using namespace  std;
int longestOnes(vector<int> &nums,int k){
   int n  = nums.size();
   int maxLen = 0;
   for (int  i = 0; i < n; i++)
   {
      //generate all the subarray and then count the zeroes
      int zeroes = 0;
      for (int j = i; j < n; j++)
      {
         if(nums[j]==0) zeroes++;
         if(zeroes<=k){
            maxLen = max(maxLen,j-i+1);
         }else break;
      }
      
   }
   return maxLen;
   // int r = 0,l=0;   
   // while (r<n)
   // {
   //    if(nums[r]==0) zeroes++;
   //    if(zeroes<=k){
   //       maxLen = max(maxLen,r-l+1);
   //    }
   //    else{
   //       if(nums[l]==0) zeroes--;
   //       l++;
   //    }
   //    r++;
   // }
   // return maxLen;
   

}
int main(){
   //code here
    int n,k;
    vector<int> nums(n,0);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      nums.push_back(x);
    }
    
    int res = longestOnes(nums,k);
    cout<<res;

    return 0;
}