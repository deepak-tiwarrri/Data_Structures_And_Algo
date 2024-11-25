#include <bits/stdc++.h>
using namespace std;
long long floorSqrt(int n)
{
   // brute force approach
   // find the sqrt of the number if nums is given
   // TC: O(n)
   // int ans = 1;
   // for (int i = 1; i <= n; i++)
   // {
   //    if (i * i <= n)
   //       ans = i;
   //    else
   //       break;
   // }
   // return ans;

   long long low = 1, high = n, ans = 1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (mid * mid <= n)
      {
         ans = mid;
         low = mid + 1;
      }
      else
         high = mid - 1;
   }
   return ans;
}
int main()
{
   // code here
   int n;
   cin >> n;
   long long res = floorSqrt(n);
   cout << res << endl;

   return 0;
}