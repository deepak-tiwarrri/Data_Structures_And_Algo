#include <bits/stdc++.h>
using namespace std;
int secondMostFrequentElement(vector<int> &nums)
{
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int res = secondMostFrequentElement(nums);
    cout << res << endl;
    return 0;
}