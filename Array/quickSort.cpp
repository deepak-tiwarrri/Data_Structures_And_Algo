#include <bits/stdc++.h>
using namespace std;
int findPartitionIndex(int low, int high, vector<int> &nums)
{
   int i = low, j = high;
   int pivot = nums[low];
   while (i < j)
   {
      while (nums[i] <= pivot && i <= high)
      {
         i++;
      }
      while (nums[j] > pivot && j >= low)
         j--;
      if (i < j)
         swap(nums[i], nums[j]);
   }
   // last swap is the pivot with the position element
   swap(nums[low], nums[j]);
   return j;
}
void quickSortFun(int low, int high, vector<int> &nums)
{
   if (low >= high)
      return;
   // pick a pivot and then perform quick sort
   int partitionIndex = findPartitionIndex(low, high, nums);
   quickSortFun(low, partitionIndex - 1, nums);
   quickSortFun(partitionIndex + 1, high, nums);
}
void quickSort(vector<int> &nums)
{
   quickSortFun(0, nums.size() - 1, nums);
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
   quickSort(nums);
   for (auto &it : nums)
   {
      cout << it << " ";
   }
   return 0;
}