#include <bits/stdc++.h>
using namespace std;
long long timeTakenToEat(vector<int> &piles, int hourly)
{
   long long totalHours = 0;
   for (int i = 0; i < piles.size(); i++)
   {
      totalHours += ceil((double)piles[i] / (double)hourly);
   }
   return totalHours;
}
int minEatingSpeed(vector<int> &piles, int h)
{
   int low = 1, high = *max_element(piles.begin(), piles.end());
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (timeTakenToEat(piles, mid) <= (long long)h)
      {
         high = mid - 1;
      }
      else
         low = mid + 1;
   }
   return low;
}
int findMax(vector<int> &v){
   int n = v.size();
   int maxi = INT_MIN;
   for(int i=0;i<n;i++){
      maxi = max(maxi,v[i]);
   }
   return maxi;
}
int minimumRateToEatBananas(vector<int> v,int h){
   int low = 1,high = findMax(v);
   while(low<=high){
      int mid = low + (high-low)/2;
      if(timeTakenToEat(v,mid)<=(long long)h)
         high = mid-1;
      else low = mid+1;
   }
   return low;
}
int main()
{

   int n,h;
   cin>>n>>h;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   // bool isRotated = searchInARotatedSortedArrayII(nums,key);
   // cout<<isRotated<<endl;
   int result = minEatingSpeed(nums, h);
   cout << result;
}