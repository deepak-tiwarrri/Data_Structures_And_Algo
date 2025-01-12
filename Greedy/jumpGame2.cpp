//return the minimum jump required to reach the end
//we can use recursion here

#include <bits/stdc++.h>
using namespace std;
int findJumps(vector<int> &nums,int jumps,int index){
    if(index>=nums.size()-1) return jumps;
    int mini = INT_MIN;
    for(int i=1;i<=nums[index];i++){
        if(index+i<nums.size()){
                    mini = min(findJumps(nums,jumps+1,index+i),mini);

        }
    }
    return mini;
}
// TC: O(N^N) and SC: O(N)
int jumpRequired(vector<int> &nums){
    //first solution using recuriosn
    // return findJumps(nums,0,0);
    int n= nums.size();
    if(n<=1) return 0; //as no jumps need
    int farthest = 0;
        int l=0,r = 0;
        int jumps = 0;
    for(int i=0;i<n-1;i++){
        farthest = max(farthest,nums[i]+i);
        if(i==r){
            r = farthest;
            l = r+1;
            jumps++;
        }
        if(r>=n-1)  break;
    }
    return jumps;
    
    
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
    int res = jumpRequired(nums);
    cout<<res<<endl;
    // return 0;

    return 0;
}