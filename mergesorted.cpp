#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
   //[1,2,2,3,5,6]
   //1 2 3 0 0 0 and 2 5 6 
   // result 1 2 3 0 0 0 2 5 6 // 0 0 0 1 2 2 5 6
   // 1 2 2 5 6 nums1 = [1,2,2,5,6]
   //for result O(m)+O(n) and sort log(m+n) and O(m)
   //sorted array
   // vector<int> ans(m+n);
   // int i=0,j=0;
   // while(i<m && j<n){
   //    if(nums1[i]<=nums2[j] && nums1[i]!=0){
   //       ans.push_back(nums1[i]);
   //       i++;
   //    }else{
   //       ans.push_back(nums2[j]);
   //       j++;
   //    }
   // }
   // while(i<m){
   //    ans.push_back(nums1[i]);
   //    i++;
   // }
   // ans = [1,2,2,3,0,0,0,5,6]
      //sort [0,0,0,1,2,2,3,5,6]
   // while (j<n)
   // {
   //    ans.push_back(nums2[j]);
   //    j++;
   // }
   // // ans = 0 0 0 1 2 2 3 5 6
   // for(int i=0;i<ans.size();i++){
   //    if(ans[i]!=0){
   //       nums
   //    }
   // }
   //nums1 = n+m
   int i=nums1.size()-1;
   int j=0;
   while(i>=0 && j<n){
      if(nums1[i]==0){
         swap(nums1[i],nums2[j]);
      }
      i--;
      j++;
   }
}
int main() {
  // code here
  int m, n;
  cin >> m >> n;
  vector<int> nums1, nums2;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    nums1.push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nums2.push_back(x);
  }
  merge(nums1, m, nums2, n);
  for (auto &it : nums1) {
    cout << it << " ";
  }
  return 0;
}