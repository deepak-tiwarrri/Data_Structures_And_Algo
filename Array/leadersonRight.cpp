#include <bits/stdc++.h>
using namespace std;
vector<int> leaders(vector<int> &nums)
{
    // vector<int> ans;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     bool isLeader = true;
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[j] > nums[i])
    //         {
    //             isLeader = false;
    //             break;
    //         }
    //     }
    //     if (isLeader)
    //         ans.push_back(nums[i]);
    // }

    // optimal approach using O(n)
    vector<int> result;
    result.push_back(nums[nums.size() - 1]);
    int maxi = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            maxi = nums[i];
            result.push_back(nums[i]);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    // code here
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> res = leaders(nums);
    for (auto &it : res)
    {
        cout << it << " ";
    }

    return 0;
}