#include<bits/stdc++.h>
using namespace  std;
vector<int> twoSum(vector<int> &arr,int n,int target){
   //brute force approach
   // for(int i=0;i<n;i++){
   //    for(int j=0;j<n;j++){
   //       if(i==j) continue;
   //       if(arr[i]+arr[j]==target){
   //          return {i,j};
   //       }
   //    }
   // }


   //better approach
   map<int,int> mpp;
   for(int i=0;i<n;i++){
      int element = arr[i];
      int more = target-element;
      if(mpp.find(more)!=mpp.end()){
         // return "YES";
         return {mpp[more],i};
      }
      mpp[element] = i;
   }
   return {}
}
int main(){
   //code here
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      arr.push_back(x);
    }
    int target = 6;
    vector<int> result = twoSum(arr,n,target);
    for(int i=0;i<result.size();i++){
      cout<<result[i]<<" ";
    }
    

    return 0;
}