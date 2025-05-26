// Given an array of n integers, find the sum of the frequencies of the highest occurring number and lowest occurring number.

// Example 1
// Input: arr = [1, 2, 2, 3, 3, 3]
// Output: 4
// Explanation: The highest frequency is 3 (element 3), and the lowest frequency is 1 (element 1). Their sum is 3 + 1 = 4.
#include <bits/stdc++.h>
using namespace std;
int sumHighestAndLowestFrequency(vector<int> &nums)
{
    unordered_map<int, int> freqHash;
    for (auto &it : nums)
    {
        freqHash[it]++;
    }
    int highestFrequency = INT_MIN;
    int lowestFrequency = INT_MAX;
    for (auto &it : freqHash)
    {
        int freq = it.second;
        highestFrequency = max(highestFrequency, freq);
        lowestFrequency = min(lowestFrequency, freq);
    }
    return lowestFrequency + highestFrequency;
}

int main()
{

    // code here
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (auto &it : nums)
    {
        cin >> it;
    }
    int res = sumHighestAndLowestFrequency(nums);
    cout << res << endl;
    return 0;
}