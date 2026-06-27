#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findFloor(vector<int> &nums,int x){
        //floor largest element in array nums[mid] <=x;
        int low  = 0,high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=x){
                ans = nums[mid];
                //move right to find the largest
                low  = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;

    }
    int findCeil(vector<int> &nums,int x){
        //ceil is smallest element in array nums[mid]>=x;
        int low  = 0,high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=x){
                ans = nums[mid];
                //move right to find the largest
                high = mid-1;
            }else{
                low  = mid+1;
            }
        }
        return ans;

    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        
        int floor = findFloor(nums,x);
        int ceil = findCeil(nums,x);
        return {floor,ceil};
    }
};

int main() {
    // code here
    int n,x;
    cin>>n>>x;
    vector<int> nums;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      nums.push_back(x);
    }
    Solution sol = Solution();
    vector<int> result = sol.getFloorAndCeil(nums,x);
    for(auto &it:result){
      cout<<it<<" ";
    }
    cout<<endl;


    return 0;
}