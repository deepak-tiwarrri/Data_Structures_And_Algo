#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
   // for (int i = 0; i < arr.size(); i++)
   // {
   //    if (arr[i] <= k)
   //       k++;
   //    else
   //       break;
   // }
   // return k;

   int low = 0, high = arr.size() - 1;
   while (low <= high)
   {
      int mid = (high - low) / 2 + low;
      int missing = arr[mid] - (mid + 1);
      if (missing < k)
         low = mid + 1;
      else
         high = mid - 1;
   }
   return low + k;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = findKthPositive(nums, k);
   cout << res << endl;
   return 0;
}