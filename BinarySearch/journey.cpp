#include <bits/stdc++.h>
using namespace std;
long long  findMinDays(vector<int> &nums,int day ){
    long long a = nums[0],b = nums[1], c= nums[2];
    long long finalDays = day/3;
    long long kilFullCycle = finalDays*(a+b+c);
    long long remainingDays = day%3;
    long long kiloMeterRemaining = 0;
    if(remainingDays>=1){
        kiloMeterRemaining+=a;
    }
    if(remainingDays>=2){
        kiloMeterRemaining+=b;
    }
    return kilFullCycle+kiloMeterRemaining;
}
void findNumberOfDays(){
    //find the alteast number of days where it travel n kilometer
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<3;++i){
       cin>>nums[i];
    }
    long long low = 1;
    // int high = *max_element(nums.begin(),nums.end());
    long long high = n;
    long long result = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(findMinDays(nums,mid)>=(long long (n))){
            result = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<result<<endl;
}
int main() 
{
    // code here
    // ios_base::sync_with_studio(0);
    // ios::sync_with_studio(nullptr);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        findNumberOfDays();
    }
   
    return 0;
}