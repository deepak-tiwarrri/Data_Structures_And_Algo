#include<bits/stdc++.h>
using namespace  std;
 vector<int> bubbleSort(vector<int>& nums) {
        //psuedo code
        
        for(int i=0;i<nums.size();i++){
            bool didSwap = false;
            for(int j=0;j<nums.size()-i-1;j++){
                //if current is greater than next swap
                if(nums[j]>nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                    didSwap = true;
                }
            }
            if(!didSwap) break;
        }
        return nums;
    }
int main(){
   //code here
    int n;
    cin>>n; 
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
      int a;
      cin>>a;
      nums.push_back(a);
    }
   auto res = bubbleSort(nums);
   for(auto &it:res) cout<<it<<" ";
   
    return 0;
}