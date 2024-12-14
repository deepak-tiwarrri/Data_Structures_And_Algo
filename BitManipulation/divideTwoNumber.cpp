// divide two number without using divison, mulitpication, and mod operator

#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
   // edge case
   // if (dividend == divisor)
   //    return 1;
   // // int sum = 0;
   // bool isPositive = true;
   // if (dividend >= 0 && divisor < 0)
   //    isPositive = false;
   // if (dividend < 0 && divisor > 0)
   //    isPositive = false;
   // dividend = abs(dividend);
   // divisor = abs(divisor);
   // while (sum + divisor <= dividend)
   // {
   //    sum += divisor;
   //    count++;
   // }
   // int ans = 0;
   // if (dividend == divisor)
   //    return 1;
   // // int sum = 0;
   // bool isPositive = true;
   // if (dividend >= 0 && divisor < 0)
   //    isPositive = false;
   // if (dividend < 0 && divisor > 0)
   //    isPositive = false;
   // dividend = abs(dividend);
   // divisor = abs(divisor);
   // int n = dividend;
   // int d = divisor;
   // while (n >= divisor)
   // {
   //    // each time n will be reduced the count will be reinitialzed to 0 to
   //    // restart
   //    int count = 0;
   //    while (d * (1 << (count + 1)) <= n)
   //    {
   //       count++;
   //    }
   //    ans += (1 << count);
   //    n = n - (d * (1 << count));
   // }
   // if (ans > INT_MAX && isPositive)
   //    return INT_MAX;
   // else if (ans > INT_MAX && !isPositive)
   //    return INT_MIN;
   // return isPositive ? ans : (-1 * ans);

   // Edge case where divisor is 1 or -1
   if (divisor == 1)
      return dividend;
   if (divisor == -1)
   {
      if (dividend == INT_MIN)
         return INT_MAX; // Overflow case
      return -dividend;
   }

   // Determine the sign of the result
   bool isPositive = (dividend >= 0) == (divisor >= 0);

   // Use long long to avoid overflow and take absolute values
   long long n = abs(1LL * dividend);
   long long d = abs(1LL * divisor);

   long long ans = 0;

   // Perform division using bit manipulation
   while (n >= d)
   {
      long long count = 0;
      while (n >= (d << (count + 1)))
         count++;
      ans += (1LL << count);
      n -= (d << count);
   }

   // Apply sign and handle overflow
   if (!isPositive)
      ans = -ans;
   if (ans > INT_MAX)
      return INT_MAX; // Clamp result to INT_MAX
   if (ans < INT_MIN)
      return INT_MIN; // Clamp result to INT_MIN

   return static_cast<int>(ans);
}
int main()
{
   // code here
   int dividend, divisor;
   cin >> dividend >> divisor;
   int res = divide(dividend, divisor);
   cout << res << endl;

   return 0;
}