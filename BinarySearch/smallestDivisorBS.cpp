#include<bits/stdc++.h>
using namespace  std;
 long long findThresholdSum(vector<int> &nums,int divisor){
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+= ceil((double)nums[i]/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(threshold<nums.size()) return -1;
        int low = 1,high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(findThresholdSum(nums,mid)<=threshold) high = mid-1;
            else low = mid+1;
            
        }
        return low;
    }
int main(){
   //code here
   int n,threshold;
   cin>>n>>threshold;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   // bool isRotated = searchInARotatedSortedArrayII(nums,key);
   // cout<<isRotated<<endl;
   int result = smallestDivisor(nums, threshold);
   cout << result;    

    return 0;
}