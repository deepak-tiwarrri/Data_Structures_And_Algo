#include<bits/stdc++.h>
using namespace  std;
int getSingleElement(vector<int> &arr){
   // for(int i=0;i<arr.size();i++){
   //    int num = arr[i];
   //    int cnt=0;
   //    for(int j=0;j<arr.size();j++){
   //       if(arr[j]==num)
   //        cnt++;
   //    }
   //    if(cnt==1)return arr[i];
   // }
   // return -1;
   
   //better approach
   // int maxi = arr[0];
   // for(int i=0;i<arr.size();++i){
   //    maxi = max(maxi,arr[i]);
   // }
   // int hash[maxi+1] = {0};
   // for(int i=0;i<arr.size();i++){
   //    hash[arr[i]]++;
   // }
   // for(int i=0;i<arr.size();i++){
   //    if(hash[arr[i]]==1) return arr[i];
   // }
   // return -1;

   //it could be solved using map data structure
   //optimal appraoch
   int xorr = 0;
   for(int i=0;i<arr.size();i++){
      xorr = xorr ^ arr[i];
   }
   return xorr;
   
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
   int res = getSingleElement(nums);
   cout<<res<<endl;
    return 0;
}