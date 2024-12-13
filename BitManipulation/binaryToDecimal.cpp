#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(string num)
{
   //    Time Complexity: O(n) Traversing every bit in the string.
   // Space Complexity: O(1) Couple of variables used.
   int sum = 0;
   int product = 1;
   for (int i = num.size() - 1; i >= 0; i--)
   {
      if (num[i] == '1')
         sum = sum + product;
      product = product * 2;
   }
   return sum;
}
int main()
{
   // code here
   string n;
   cin >> n;
   int res = binaryToDecimal(n);
   cout << res << endl;

   return 0;
}