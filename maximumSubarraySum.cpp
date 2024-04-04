#include <bits/stdc++.h>
using namespace std;
long long maxSubArraySum(vector<int> arr, int n)
{
   int sum = 0;
   long long maxSum = INT_MIN;
   for (int i = 0; i < n; i++)
   {
      //for printing the sub array
      //sum should be zero 
      // if(sum==0) start = i;
      sum += arr[i];
      if (sum > maxSum)
         maxSum = sum;
         //ansStart = start
         //ansEnd = i;
      if (sum < 0)
         sum = 0;
   }
   return maxSum;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   int result = maxSubArraySum(arr, n);
   cout << result;
   return 0;
}