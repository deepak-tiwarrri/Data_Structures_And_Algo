#include <bits/stdc++.h>
using namespace std;
int atMostKDistinctInt(vector<int> &nums, int k)
{
    // tough problem this type of problem can be asked in interview
    unordered_map<int, int> numMap;
    int r = 0, l = 0;
    int count = 0;
    if (k <= 0)
        return 0; // edge case cause when we are substracting k-1 it can become negative so in that case count will be zero
    while (r < nums.size())
    {
        numMap[nums[r]]++;
        while (numMap.size() > k)
        {
            numMap[nums[l]]--;
            if (numMap[nums[l]] == 0)
                numMap.erase(nums[l]);
            l++;
        }
        if (numMap.size() <= k)
        {
            count = count + (r - l + 1);
        }
        r++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    // unordered_map<int,int> mpp;
    // int cnt=0;
    // //brute force approach
    // // for(int i=0;i<nums.size();i++){
    // //     mpp.clear();
    // //     for(int j=i;j<nums.size();j++){
    // //         mpp[nums[j]]++;
    // //         if(mpp.size()==k) cnt = cnt+1;
    // //         else if(mpp.size()>k) break;
    // //     }
    // // }

    // return cnt;
    return atMostKDistinctInt(nums, k) - atMostKDistinctInt(nums, k - 1);
}
int main()
{
    // code here
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int res = subarraysWithKDistinct(nums, k);
    cout << res;

    return 0;
}