#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxOnes = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            count++;
            maxOnes = max(count, maxOnes);
        }
        else
        {
            count = 0;
        }
    }
    return maxOnes;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int res = findMaxConsecutiveOnes(nums);
    cout << res << endl;
    return 0;
}