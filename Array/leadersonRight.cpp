#include<bits/stdc++.h>
using namespace  std;
vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     int leader = nums[i];
        //     int flag = true;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[j]>leader){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag){
        //         ans.push_back(leader);
        //     }
        // }
        // return ans;
        int maxOnRight = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>maxOnRight){
                ans.push_back(nums[i]);
                maxOnRight = nums[i];
            }
        }
        //at last reverse the array to get desired output
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
   //code here
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      nums.push_back(x);
   }    
   vector<int> res = leaders(nums);
   for (auto &it : res)
   {
      cout<<it<<" ";
   }
   

    return 0;
}