
#include <bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int> &A, int key)
{
   // Write your code here.
   //[3,4,5,1,2,3,3,3,3,3]
   //[7,8,9,1,2,3,4,5,6]
   int low = 0, high = A.size() - 1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (A[mid] == key)
         return 1;
      else if (A[mid] == A[low] && A[mid] == A[high])
      {
         low = low + 1;
         high = high - 1;
         continue;
      }
      if (A[low] <= A[mid])
      {
         // left is sorted it means
         if (A[low] <= key && key <= A[mid])
         {
            high = mid - 1;
         }
         else
            low = mid + 1;
      }
      else
      {
         if (A[mid] <= key && key <= A[high])
            low = mid + 1;
         else
            high = mid - 1;
      }
   }
   return 0;
}
int findMinimum(vector<int> nums, int n)
{
   int low = 0, high = n - 1;
   int minVal = INT_MAX;
   while (low <= high)
   {
      int mid = (high - low) / 2 + low;
      if(nums[low]<=nums[high]) minVal = min(minVal,nums[low]);
      if (nums[low]<=nums[mid])
      {
         // it means left half is sorted
         minVal = min(minVal, nums[low]);
         low = mid + 1;
      }
      else
      {
         minVal = min(minVal, nums[mid]);
         high = mid - 1;
      }
   }
   return minVal;
   //mid = 1
   // 4<=3
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
   // bool isRotated = searchInARotatedSortedArrayII(nums,key);
   // cout<<isRotated<<endl;
   int result = findMinimum(nums, n);
   cout << result;
}