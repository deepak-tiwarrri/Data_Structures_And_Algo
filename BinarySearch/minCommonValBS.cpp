#include <bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> &nums,int x){
    int low = 0,high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>x){
            low = mid+1;
        }else if(nums[mid]==x) return true;
        else high = mid-1;
    }
    return false;
}
int getCommon(vector<int> &nums1,vector<int> &nums2){
    // set<int> hashSet;
    // for (auto &itr : nums1) {
    //     hashSet.insert(itr);
    // }
    // for(auto &itr:nums2){
    //     if(hashSet.find(itr)!=hashSet.end()) return itr;
    // }
    // return -1;

    // int l = 0,r = 0;
    int n = nums1.size(),m= nums2.size();
    // while(l<n && r<m){
    //     if(nums1[l]<nums2[r]){
    //         l++;
    //     }else if(nums1[l]==nums2[r]) return nums1[l];
    //     else if(nums1[l]>nums2[r])r++;
    // }
    // return -1;
    if(n>m){
        for(int i=0;i<m;i++){
            if(binarySearch(nums1,nums2[i])){
                return nums2[i];
            }else continue;
        }
    }else{
        for(int i=0;i<n;i++){
            if(binarySearch(nums2,nums1[i])) return nums1[i];
            else continue;
        }
    }
    return -1;
}
int main() {
    // code here
     int n,m;
     cin>>n>>m;
    vector<int> nums1,nums2;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums1.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        nums2.push_back(x);
    }
    int res = getCommon(nums1,nums2);
    cout<<res;
    return 0;

    return 0;
}