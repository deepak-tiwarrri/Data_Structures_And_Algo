
#include <bits/stdc++.h>
using namespace std;
int singleElement(vector<int> &nums,int n){
   int low = 1,high = n-2;
   if(n==1) return nums[0];
   if(nums[0]!=nums[1]) return nums[0];
   if(nums[n-1]!=nums[n-2]) return nums[n-1];
   while(low<=high){
      int mid = (high-low)/2 + low;
      if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
      else if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])) {
         low = mid+1;
      }else{
         high = mid-1;
      }
   }
   return -1;
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
   int result = singleElement(nums, n);
   cout << result;
}