#include<bits/stdc++.h>
using namespace  std;
  double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<double> averages;
        int left=0,right = nums.size()-1;
        while(left<right){
            int minEle = nums[left++];
            int maxEle = nums[right--];
            double avg = (minEle+maxEle)/2.0;
            averages.push_back(avg);
        }
        double minAverages=averages[0];
        for(double i=0;i<averages.size();i++){
            minAverages = min(averages[i],minAverages);
        }
        return minAverages;

    }
int main(){
   //code here
   int n;
   cin>>n;
   vector<int> nums(n,0);
   for(auto &it:nums) cin>>it;
   double res = minimumAverage(nums);
   cout<<res;    

    return 0;
}