#include <bits/stdc++.h>
using namespace std;
vector<int> mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n) {

  int i = 0, j = 0;
  vector<int> mergedArray;
  while (i < m && j < n) {
    if (nums1[i] <= nums2[j]) {
      mergedArray.push_back(nums1[i]);
      i++;
    } else {

      mergedArray.push_back(nums2[j]);
      j++;
    }
  }
  while (i < m) {
    mergedArray.push_back(nums1[i]);
    i++;
  }
  while (j < n) {
    mergedArray.push_back(nums2[j]);
    j++;
  }
  return mergedArray;
}
void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int indx1,
                   int indx2) {
  if (nums1[indx1] > nums2[indx2]) {
    swap(nums1[indx1], nums2[indx2]);
    indx1++, indx2++;
  }
}
void mergeTwoArray(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int len = m + n;
  int gap = (len / 2) + (len % 2);
  int left = 0, right = left + gap;
  while (gap > 0) {
    while (right < n) {
      if (left <= m && right <= n) {
        swapIfGreater(nums1, nums2, left, right - m);
      } else if (left <= m && right <= m) {
        swapIfGreater(nums1, nums2, left, right);
      } else {
        swapIfGreater(nums1, nums2, left - m, right - m);
      }
      left++, right++;
    }
    if (gap == 1)
      break;
    gap = gap / 2;
  }
}
void merge(vector<int> &nums1,int n,vector<int> &nums2,int m){
  int left = n-1;
  int right = 0;
  while (left>=0 && right<m)
  {
    if(nums1[left]>=nums2[right]){
      swap(nums1[left],nums2[right]);
      left--,right++;
    }else{
      break;
    }
  }
  sort(nums1.begin(),nums1.end());
  sort(nums2.begin(),nums2.end());
}
int main() {
  // code here
  int m, n;
  cin >> m >> n;
  vector<int> num1, num2;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    num1.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    num2.push_back(x);
  }
  // vector<int> ans = mergeSortedArray(num1, m, num2, n);
   merge(num1, m, num2, n);
//   for (auto &item : ans) {
//     cout << item << " ";
//   }
   for(auto &it:num1){
      cout<<it<<" ";
   }
   for(auto &it1:num2){
      cout<<it1<<" ";
   }
  return 0;
}