#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums,int x){
    int ans = nums.size();
    int low  =0,high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)>>2;
        if(nums[mid]>=x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int maxiCount(vector<int> &nums){
    int pos = lowerBound(nums,1);
    int zero = lowerBound(nums,0);
    int n = nums.size();
    return max(n-pos,zero);
}
int main() {
    // code here
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }    
    int res = maxiCount(nums);
    cout<<res;
    return 0;
}