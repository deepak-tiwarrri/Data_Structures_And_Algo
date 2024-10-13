#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums){
    //go from i to nums.size() inclusive
    // brute force approach
    for(int i=0;i<=nums.size();++i){
        bool flag = false;
        for(int j=0;j<nums.size();++j){
            // code goes here
            if(nums[j]==i){
                flag = true;
                break;
            }
        }
        if(flag == false) return i;
    }
    return -1;
    //second appraoch using hashing SC:O(n+1)
    int n = nums.size();
    int freqHash[n+1] = {0};
    for(int i=0;i<n;i++){
        freqHash[nums[i]]++;
    }
    for (int i = 0; i <=n; i++)
    {   
        if(freqHash[i]==0) return i;
    }
    return -1;
     int n = nums.size();
    long long sumOfN = (n*(n+1)/2);
    long long sumTillN = 0;
    for(int i=0;i<n;++i){
        sumTillN+= nums[i];
    }
    return static_cast<int>(sumOfN-sumTillN);
    int xor1 = 0,xor2=0;
    for(int i=0;i<nums.size();i++){
        // xor1 = xor1^i;//both line are right
        xor1 = xor1 ^(i+1);
        xor2 = xor2^nums[i];
    }
    //xor of 0 and any number is always 0
    //that is why loop take xor of [1...N]
    // return xor1^xor2^n;
    return xor1^xor2;
    
}
int main(){
  
  //code here
    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        nums.push_back(x);
    }    
    int res = missingNumber(nums);
    cout<<res<<endl;
  
  return 0;
}