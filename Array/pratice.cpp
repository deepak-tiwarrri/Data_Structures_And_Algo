#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mergeTwoArray(int low, int mid, int high, vector<int> &nums)
{
  long long int cnt = 0;
  int left = low;
  int right = mid + 1;
  // vector<int> temp
  vector<int> temp;
  while (left <= mid && right <= high)
  {
    if (nums[left] <= nums[right])
    {
      temp.push_back(nums[left]);
      left++;
    }
    else
    {
      cnt += (mid - left + 1);
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
  for (int i = low; i <= high; i++)
  {
    nums[i] = temp[i - low];
  }

  return cnt;
}
int mergeSort(int low, int high, vector<int> &nums)
{
  long long int cnt = 0;
  if (low == high)
    return cnt;
  int mid = low + (high - low) / 2;
  cnt += mergeSort(low, mid, nums);
  cnt += mergeSort(mid + 1, high, nums);
  cnt += mergeTwoArray(low, mid, high, nums);
  return cnt;
}

int inversionCount(vector<int> &arr)
{
  // Code Here
  int cnt = mergeSort(0, arr.size() - 1, arr);
  return cnt;
}

int reversePair(vector<int> &arr){

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
  int cnt = reversePair(nums);
  // int cnt = inversionCount(nums);
  cout << "Reverse Pair are: " << cnt << endl;
  return 0;
}
