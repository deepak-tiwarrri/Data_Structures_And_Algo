#include <bits/stdc++.h>
using namespace std;
int countSetBit(int n)
{
   // use brute force that is convert number to binary and if the reminder is 1 increase the count
   int count = 0;
   while (n > 0)
   {
      // if (n % 2 == 1)
      //    count++;
      // n = n / 2;

      // more faster version is using bit manipulation
      // count += (n & 1);
      // n = n >> 1;

      // more optimal code is
      n = (n & (n - 1));
      count++;
   }
   return count;
}
int main()
{
   // code here
   // code here
   int n;
   cin>>n;
   int res = countSetBit(n);
   cout << res << endl;
   return 0;
}