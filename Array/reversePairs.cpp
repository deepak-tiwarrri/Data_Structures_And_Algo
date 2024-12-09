#include <bits/stdc++.h>
using namespace std;
int findReversePairCount(int low, int mid, int high, vector<int> nums)
{
   int right = mid + 1;
   int count = 0;
   for (int i = low; i <= mid; i++)
   {
      while (right <= high && nums[i] > 2 * nums[right])
         right++;
      count = count + (right - (mid + 1));
   }
   return count;
}
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
   // call findreversePair count function there before merging
   count += findReversePairCount(low, mid, high, nums);
   count += mergeTwoArray(low, mid, high, nums);
   return count;
}
int reversePairs(vector<int> &nums)
{
   int n = nums.size();
   int count = 0;
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       if (nums[i] > nums[j] * 2)
   //          count++;
   //    }
   // }
   // return count;
   return mergeSorted(0, nums.size() - 1, nums);
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
   int res = reversePairs(nums);
   cout << res << endl;

   return 0;
}