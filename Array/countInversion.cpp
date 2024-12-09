#include <bits/stdc++.h>
using namespace std;
long long int mergeTwoArray(int low, int mid, int high, vector<int> &nums)
{
   int left = low;
   long long int count = 0;
   vector<int> temp;
   int right = mid + 1;
   while (left <= mid && right <= high)
   {
      if (nums[left] <= nums[right])
      {
         temp.push_back(nums[left]);
         left++;
      }
      else
      {
         count += (mid - left + 1);
         temp.push_back(nums[right]);
         right++;
      }
   }
   while (left <= mid)
   {
      temp.push_back(nums[left]);
      left++;
   }
   while (right <= high)
   {
      temp.push_back(nums[right]);
      right++;
   }
   // put all the element of array from temp back to original array
   for (int i = low; i <= high; i++)
   {
      nums[i] = temp[i - low];
   }
   return count;
}
long long int mergeSorted(int low, int high, vector<int> &nums)
{
   long long int count = 0;
   if (low == high)
      return count;
   long long int mid = (low + high) / 2;
   count += mergeSorted(low, mid, nums);
   count += mergeSorted(mid + 1, high, nums);
   count += mergeTwoArray(low, mid, high, nums);
   return count;
}
long long int numberOfInversions(vector<int> nums)
{
   // brute force will be easy using O(n2)
   // int count = 0;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    for (int j = i + 1; j < nums.size(); j++)
   //    {
   //       /* code */
   //       if (nums[i] > nums[j])
   //          count++;
   //    }
   // }
   // return count;

   return mergeSorted(0, nums.size() - 1, nums);
}
int main()
{
   // code here
   // given array find the count of pair such that
   // i<j and arr[i]>arr[j]
   int n;
   cin >> n;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   long long int res = numberOfInversions(nums);
   cout << res;

   return 0;
}