#include <bits/stdc++.h>
using namespace std;
void sort012(vector<int> &nums){
    int low =0;
    int mid = 0;
    int high = nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
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
    sort012(nums);
    for(auto &it:nums){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}