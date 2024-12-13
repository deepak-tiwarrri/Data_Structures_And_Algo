#include <bits/stdc++.h>
using namespace std;
int findXOR(int n)
{
   // brute force approach for solving this is finding all the xor
   //  int xoR = 0;
   //  for (int i = 1; i <= n; i++)
   //  {
   //     xoR = xoR ^ i;
   //  }
   //  return xoR;
   if (n % 4 == 1)
      return 1;
   else if (n % 4 == 2)
      return n + 1;
   else if (n % 4 == 3)
      return 0;
   else
      return n;
}
int findRangeXOR(int l, int r)
{
   return findXOR(l - 1) ^ findXOR(r);
}
int main()
{
   // code here
   int l, r;
   cin >> l >> r;
   int res = findRangeXOR(l, r);
   cout << res << endl;

   return 0;
}