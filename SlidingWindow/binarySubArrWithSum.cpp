#include <bits/stdc++.h>
using namespace std;
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

    
}
int main()
{
   // code here
   int n,goal;
   cin>>n>>goal;
   vector<int> nums(n,0);
   for (int i = 0; i < n; i++)
   {
      cin>>nums[i];
   }
   int result = numSubarraysWithSum(nums,goal);
   cout<<result;   
   return 0;
}