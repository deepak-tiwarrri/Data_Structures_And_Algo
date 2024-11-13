#include<bits/stdc++.h>
using namespace  std;
void insertionSort(vector<int> &nums,int n){
   
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
   insertionSort(nums,n);
   for (auto &it : nums)
   {
      cout<<it<<" ";
   }
   
    return 0;
}