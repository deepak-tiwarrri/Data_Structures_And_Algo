#include<bits/stdc++.h>
using namespace std;
int findHowManyTimesArrayRotated(vector<int> &nums,int n){
  int low = 0, high = n - 1;
  int miniIndex = INT_MAX;
  int miniValue = INT_MAX;
  while(low<=high){
    //find the index of the minimum element that many times array is rotated simple
    int mid = low + (high - low) / 2;
    if(nums[low]<=nums[high]){
      if(nums[low]<miniValue){
        miniIndex = low;
        miniValue = nums[low];
      }
      break;
    }else if(nums[low]<=nums[mid]){
      //that means left half is sorted, take the left and move right
      if(nums[low]<=miniValue){
        miniIndex = low;
        miniValue = nums[low];
      }
      low = mid + 1;
    }else{
      if(nums[mid]<miniValue){
        miniIndex = mid;
        miniValue = nums[mid];
      }
      high = mid - 1;
    }
  }
  return miniIndex;
}
int main(){
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
   int result = findHowManyTimesArrayRotated(nums, n);
   cout << result;


return 0;
}