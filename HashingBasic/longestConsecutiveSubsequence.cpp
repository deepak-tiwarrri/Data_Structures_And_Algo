#include <bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int> &nums, int x)
{
   int isFound = false;
   for (int i = 0; i < nums.size(); i++)
   {
      if (nums[i] == x)
      {
         isFound = true;
      }
   }
   return isFound;
}
int longestConsecutive(vector<int> &nums)
{
   // find the max count //brute force approach
   // int longest = 0;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    int x = nums[i];
   //    int cnt = 1;
   //    while (linearSearch(nums, x + 1) == true)
   //    {
   //       x++;
   //       cnt++;
   //    }
   //    longest = max(longest, cnt);
   // }
   // return longest;

   // better approach  O(logn)+O(n)
   //  sort(nums.begin(), nums.end());
   //  int cnt = 0, longest = 1;
   //  int smallestTillNow = INT_MIN;
   //  for (int i = 0; i < nums.size(); i++)
   //  {
   //     if (nums[i] - 1 == smallestTillNow)
   //     {
   //        cnt++;
   //        smallestTillNow = nums[i];
   //     }
   //     else if (smallestTillNow != nums[i])
   //     {
   //        cnt = 1;
   //        smallestTillNow = nums[i];
   //     }
   //     longest = max(longest, cnt);
   //  }
   //  return longest;

   // optimal is using O(n) and SC: O(n)
   int longest = 1;
   unordered_set<int> hashSet;
   for (auto &it : nums)
   {
      hashSet.insert(it);
   }
   for (auto &it : hashSet)
   {
      int x = it;
      int cnt = 1;

      // if the x-1 is present eg 1 and 0 is present in the set then
      if (hashSet.find(x - 1) == hashSet.end()){
      while (hashSet.find(x + 1) != hashSet.end())
      {
         cnt++;
         x++;
      }
      longest = max(longest, cnt);
      }
   }
   return longest;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = longestConsecutive(nums);
   cout << res << endl;

   return 0;
}