#include<bits/stdc++.h>
using namespace  std;
void findCombinations(int indx,int target,vector<int> &candidates,vector<vector<int>> &ansArr,vector<int> &temp){
   if(indx==candidates.size()){
      if(target==0) ansArr.push_back(temp);
      //if target is not zero and we reached the end then return it
      return;
   }
   if(candidates[indx]<=target){
      //if the element that we are picking is less than target then only pick it
      temp.push_back(candidates[indx]);
      findCombinations(indx,target-candidates[indx],candidates,ansArr,temp);
      //coming back pop the value in the ds
      temp.pop_back();
   }
   ///now move to the no pick combination
   findCombinations(indx+1,target,candidates,ansArr,temp);
}
vector<vector<int>> combinationSum(vector<int> &candidates,int target){
   //combination sum is easy problem but recursion concept should be clear
   //we can pick same index multiple times 
   // so each index has more than pick and non pick
   //if index that we are picking is more than the target required then don't pick it, it should be less than target

   vector<vector<int>> ansArr;
   vector<int> temp;
   findCombinations(0,target,candidates,ansArr,temp);
   return ansArr;
}
int main(){
   //code here
    int n, target;
   cin >> n >> target;
   // int arr[n];
   vector<int> arr(n, 0);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   
   vector<vector<int>> ans = combinationSum(arr, target);
   for (auto &it : ans)
   {
      for (auto &el : it)
         cout << el << " ";
      cout << endl;
   }

    return 0;
}