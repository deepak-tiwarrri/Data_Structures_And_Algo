// Given an array of n integers representing the burst times of processes, determine the average waiting time for all processes and return the closest whole number that is less than or equal to the result.
// Example 1
// Input : bt = [4, 1, 3, 7, 2]
// Output : 4
// Explanation : The total waiting time is 20.
// So the average waiting time will be 20/5 => 4.
// Example 2
// Input : bt = [1, 2, 3, 4]
// Output : 2
// Explanation : The total waiting time is 10.
// So the average waiting time will be 10/4 => 2.

#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &bt){
    //first sort the waiting time
    sort(bt.begin(),bt.end());
    long long timeTaken = 0;
    long long totalWaitingTime = 0;
    for(auto &it:bt){
        //first add the timeTaken to totalWaiting time
        totalWaitingTime+= timeTaken;
        timeTaken+= it;
    }
    return (long long)totalWaitingTime/bt.size();
}
int main() {
    // code here
   cin.tie(0);cout.tie(0);
        int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long res = solve(nums);
    cout<<res<<endl;
    return 0;


    return 0;
}