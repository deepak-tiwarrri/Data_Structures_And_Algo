// to find lower bound or upper bound array or vector should be in sorted format ascending order

#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &nums, int x)
{
    // find smallest index such that arr[index]>x
    int upperBoundIndex = nums.size();
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x)
        {
            upperBoundIndex = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return upperBoundIndex;
}
int lowerBound(vector<int> &nums, int x)
{
    //smallest index such that arr[index]>=x
    int n = nums.size();
    int lowerBoundIndx = n;
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (nums[mid] >= x)
        {
            lowerBoundIndx = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return lowerBoundIndx;
}
int main()
{
    // int n;
    // cin >> n;
    // // int a[n];
    // vector<int> a(n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> a[i];
    // }
    // sort(a.begin(), a.end());

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // // int *ptr = lower_bound(a, a + n, 8);
    // auto itr = upper_bound(a.begin(), a.end(), 8);

    // if ((itr) == (a.end()))
    // {
    //     cout << "Not found";
    //     return 0;
    // }
    // cout << *itr << endl;
    // this has the time complexity of O(n) not O(log(n))
    // auto itr = lower_bound(s.begin(), s.end(), 29);
    // auto itr = s.upper_bound(5);
    // auto itr = s.upper_bound(5);
    // cout << (*itr) << endl;

    int n, x;
    cin >> n >> x;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int res = lowerBound(nums, x);
    cout << res << endl;

    return 0;
}