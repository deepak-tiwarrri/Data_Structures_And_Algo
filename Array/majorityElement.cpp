#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
   int n = nums.size();
   int cnt = 0, ele = -1;
   for (int i = 0; i < n; i++)
   {
      if (cnt == 0)
      {
         ele = nums[i];
         cnt = 1;
      }
      else if (nums[i] == ele)
      {
         cnt++;
      }
      else
      {
         cnt--;
      }
   }
   return ele;
}
int majorityElementExample(vector<int> &nums){
   //brute force
// Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
// Output: 7
// Explanation:
// The number 7 appears 5 times in the 9 sized array
// Example 2
// Input: nums = [1, 1, 1, 2, 1, 2]
// Output: 1
unordered_map<int,int> mpp;
int n = nums.size();
for(int i=0;i<nums.size();i++){
   mpp[nums[i]]++;
}
for(auto &it:mpp){
   if(it.second>n/2){
      return it.first;
   }
}
return -1;
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
   int res = majorityElementExample(nums);
   cout << res << endl;

   return 0;
}