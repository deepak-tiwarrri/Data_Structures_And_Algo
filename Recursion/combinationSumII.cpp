#include<bits/stdc++.h>
using namespace  std;
void findCombination(int indx,vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> &ds){
   if(target==0){
      ans.push_back(ds);
      return;
   }
   for(int i=indx;i<candidates.size();i++){
      if(i>indx && candidates[i]==candidates[i-1]) continue;
      if(candidates[i]>target) break;
      ds.push_back(candidates[i]);
      findCombination(i+1,candidates,target-candidates[i],ans,ds);
      ds.pop_back();
   }

}

vector<vector<int>> combinationSumII(vector<int> &candidates,int target){
   sort(candidates.begin(),candidates.end());
   vector<vector<int>> ans;
   vector<int> ds;
   findCombination(0,candidates,target,ans,ds);
   return ans;
}
int main(){
   //code here
    int n, target;
   cin >> n >> target;
   // int arr[n];
   vector<int> arr(n, 0);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   
   vector<vector<int>> ans = combinationSumII(arr, target);
   for (auto &it : ans)
   {
      for (auto &el : it)
         cout << el << " ";
      cout << endl;
   }

    return 0;
}