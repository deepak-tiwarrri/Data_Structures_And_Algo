#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums, int x)
{
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
int firstOccurence(vector<int> &nums,int target){
   int low = 0;
   int high = nums.size() - 1;
   int ans = -1;
   while(low<=high){
      int mid = low + (high - low) / 2;
      if(nums[mid]==target){
         ans = mid;
         high = mid - 1;
      }else if(target>nums[mid]){
         low = mid + 1;
      }else
         high = mid - 1;
   }
   return ans;
}
int lastOccurence(vector<int> &nums,int target){
   int low = 0;
   int high = nums.size() - 1;
   int ans = -1;
   while(low<=high){
      int mid = low + (high - low) / 2;
      if(nums[mid]==target){
         ans = mid;
         low = mid + 1;
      }else if(target>nums[mid]){
         low = mid + 1;
      }else
         high = mid - 1;
   }
   return ans;
}
vector<int> firstAndLastOccurence(vector<int> &nums, int target)
{
   // brute force taking TC: O(n) and SC: O(1)
   //  int first = -1, last = -1;
   //  for (int i = 0; i < nums.size(); i++)
   //  {
   //     if (nums[i] == target)
   //     {
   //        if (first == -1)
   //           first = i;
   //        last = i;
   //     }
   //  }
   //  return {first, last};
   // it can be optimed using lower and upper bound
   // if lower bound is not equal to target it means number is not present
   // also if lower bound is equal to n that mean number is not present
   // upper bound -1 will be the last occurence of element
   // int lb = lowerBound(nums, target);
   // int ub = upperBound(nums, target);
   // if (nums[lb] != target || nums[lb] == nums.size())
   //    return {-1, -1};
   // return {lb, ub - 1};
   //TC of the above approach is O(logn+logn) and SC: O(1);

   // to further optimized this code we can use binary search
   int first = firstOccurence(nums, target);
   int last = lastOccurence(nums,target);
   return {first, last};
}
int main()
{
   // code here
   int n, target;
   cin >> n >> target;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   vector<int> firstAndLastAns = firstAndLastOccurence(nums, target);
   for (auto &it : firstAndLastAns)
      cout << it << " ";

   return 0;
}