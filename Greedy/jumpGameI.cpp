//return the maximum index till u can reach if it can reach the end 
//of the array then return true or else return false

#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums){
    int maxJumps = 0;
    for(int i=0;i<nums.size();i++){
        if(i>maxJumps) return false;
        if(maxJumps>=(nums.size()-1)) return true;
        if(nums[i]+i>maxJumps){
            maxJumps = nums[i]+i;
        }else continue;
    }
    return true;
}
int main() {
    // code here
   cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }    
    bool isPossible = canJump(nums);
    if(isPossible) cout<<"yes";
    else cout<<"no";

    return 0;
}