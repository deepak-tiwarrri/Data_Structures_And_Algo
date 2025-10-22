#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutationNumber(vector<int> &nums)
{
   //[2,1,5,4,3,0,0]
   // find the first element that is less than it's right take it's index
   int n = nums.size();
   int index = -1;
   for (int i = n - 2; i >= 0; i--)
   {
      if (nums[i] < nums[i + 1])
      {
         index = i;
         break;
      }
   }
   if (index == -1)
   {
      // if index is -1 that means dip is not found and that number is greater
      reverse(nums.begin(), nums.end());
      return nums;
   }
   // if found that means u have to swap that index value to first greater value on the right
   for (int i = n - 1; i >= 0; i--)
   {
      if (nums[i] > nums[index])
      {
         swap(nums[i], nums[index]);
         break;
      }
   }
   reverse(nums.begin() + index + 1, nums.end());
   return nums;
}

int main()
{
   // code here
   int n;
   cin >> n;

   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   vector<int> res = nextPermutationNumber(nums);
   for (auto &ele : res)
   {
      cout << ele << " ";
   }

   return 0;
}