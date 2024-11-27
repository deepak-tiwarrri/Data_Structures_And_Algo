#include <bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int> &stalls, int n, int dist, int k)
{
   int lastPlaced = stalls[0];
   int countCow = 1;
   for (int i = 1; i < n; i++)
   {
      int diff = stalls[i] - lastPlaced;
      if (diff >= dist)
      {
         countCow++;
         lastPlaced = stalls[i];
      }
   }
   return countCow >= k;
}
// k is the number of cow
int aggressiveCow(int n, int k, vector<int> &stalls)
{
   // for brute force sort the array and use for loop
   // sort(stall.begin(),stall.end());
   // sort(stalls.begin(), stalls.end());
   // for (int i = 1; i <= (stalls[n - 1] - stalls[0]); ++i)
   // {
   //    if (canWePlace(stalls, n, i, k))
   //       continue;
   //    else
   //       return (i - 1);
   // }
   // return -1;
   if(k>n) return -1;
   sort(stalls.begin(),stalls.end());
   int low = 1,high = stalls[n-1]-stalls[0];
   while(low<=high){
      int mid = low + (high-low)/2;
      //if we are able to place the cow then search for maximum and move right
      if(canWePlace(stalls,n,mid,k)) low = mid+1;
      else high = mid-1;
   }
   return high;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> nums(n);
   for (auto &it : nums)
   {
      cin >> it;
   }
   int result = aggressiveCow(n, k, nums);
   cout << result;
   return 0;
}