#include <bits/stdc++.h>
using namespace std;
int func(int val, int N)
{
   int product = 1;
   for (int i = 1; i <= N; ++i)
   {
      product = product * val;
   }
   return product;
}
int NthRoot(int N, int M)
{
   // n = 3 m = 27
   // brute force approach using linear search
   // for (int i = 1; i <= M; i++)
   // {
   //    /* code */
   //    if (func(i, N) == M)
   //       return i;
   //    else if (func(i, N) > M)
   //       break;
   // }
   // return -1;

   int low = 1, high = M;
   //  int ans = -1;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (pow(mid, N) == M)
         return mid;
      if ((pow(mid, N)) > M)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return -1;
}
int main()
{
   // code here
   int N, M;
   cin >> N >> M;
   int res = NthRoot(N, M);
   cout << res << endl;

   return 0;
}