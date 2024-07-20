// #include <bits/stdc++.h>
// using namespace std;
// int minimumOperations(vector<int> &nums)
// {
//    // int mini = INT_MAX;
//    int cnt = 0;
//    for (int i = 0; i < nums.size(); i++)
//    {
//       if (nums[i] % 3 != 0)
//       {
//          if ((nums[i] + 1) % 3 == 0 || (nums[i] - 1) % 3 == 0)
//             cnt++;
//       }
//    }
//    return cnt;
// }
// int minOperations(vector<int> &nums)
// {
//    int n = nums.size();
//    int ans = 0, cnt = 0;
//    if (n < 3)
//       return -1;
//    int i = 0;
//    while (i <= n - 3)
//    {
//       if (nums[i] == 0)
//       {
//          nums[i] = 1 - nums[i];
//          nums[i + 1] = 1 - nums[i + 1];
//          nums[i + 2] = 1 - nums[i + 2];
//          cnt++;
//       }
//       i++;
//    }
//    for (auto &ele : nums)
//    {
//       if (ele == 0)
//          return -1;
//    }
//    return cnt;
// }
// int countPairs(vector<int> &nums, int target)
// {
//    sort(nums.begin(), nums.end());
//    int cnt = 0;
//    for (int i = 0; i < nums.size()-1; i++)
//    {
//       int j = i + 1;
//       cout<<j<<endl;
//       while (j < nums.size())
//       {
//          if (nums[j] + nums[i] < target )
//             cnt++;
//          else
//             break;
//          j++;
//       }
//    }
//    return cnt;
// }
// int main()
// {
//    // code here
//    // int n,target;
//    // cin >> n>>target;
//    // vector<int> nums(n, 0);
//    // for (auto &it : nums)
//    //    cin >> it;
//    // // int res = minimumOperations(nums);
//    // int res = countPairs(nums,target);
//    // cout << res << endl;

   

//    return 0;
// }
#include <iostream>
// #include <cmath>
using namespace std;
int main() {
   //  double x = 32.14, y = 12.552, z = 91.78;
   float val = 9/2;
   //  // Rounding to one decimal place
   //  std::cout << "Rounded value of " << x << ": " << std::round(x) << "\n";
   //  std::cout << "Rounded value of " << y << ": " << std::round(y) << "\n";
   //  std::cout << "Rounded value of " << z << ": " << std::round(z) << "\n";
    cout<<val<<endl;

    return 0;
}
