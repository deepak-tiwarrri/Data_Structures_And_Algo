#include<bits/stdc++.h>
using namespace  std;

  int subArraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        int preSum = 0,cnt = 0;
        mpp[0] = 1;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int remove = preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]++;
        }
        return cnt;
    }
int main(){
   //code here
   int n;
   cin>>n;
   int k;
   cin>>k;
   vector<int> nums;

for(int i=0;i<n;i++){
   int x;
   cin>>x;
   nums.push_back(x);
}
int result = subArraySum(nums,k);
cout<<result;


    return 0;
}