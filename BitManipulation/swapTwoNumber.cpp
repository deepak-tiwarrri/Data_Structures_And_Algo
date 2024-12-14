void swapToNumber(int a, int b)
{
   // use xor operator
   //  int temp = a;
   //  a = b;
   //  b = temp;

   // using xor operator without using temp
   a = a ^ b;
   b = a ^ b;
   b = a ^ b;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
   // code here
   int a, b;
   cin >> a >> b;
   swapToNumber(a, b);
   cout << a << " " << b;

   return 0;
}