#include<bits/stdc++.h>
using namespace  std;
void allSubsequence(int indx,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){

   if(indx ==nums.size()){
      ans.push_back(ds);
      return;
   }
   ds.push_back(nums[indx]);
   allSubsequence(indx+1,nums,ds,ans);
   ds.pop_back();
   allSubsequence(indx+1,nums,ds,ans);
}
vector<vector<int>> subsets(vector<int> &nums){
   vector<vector<int>> ans;
   vector<int> ds;
   allSubsequence(0,nums,ds,ans);
   return ans;
}
int main(){
   //code here
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(auto &it:nums) cin>>it;
    vector<vector<int>> res = subsets(nums);
    for(auto &it:res){
      for(auto &el:it){
         cout<<el<<" ";
      }
      cout<<endl;
    }

    return 0;
}