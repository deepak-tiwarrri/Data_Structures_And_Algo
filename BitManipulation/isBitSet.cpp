#include <bits/stdc++.h>
using namespace std;
bool isBitSet(int n, int i)
{
   // string bin = decimalToBinary(n);
   // for (int j = bin.size() - 1; j >= 0; j--)
   // {
   //    if (j - i - 1 == i && bin[j] == 1)
   //       return 0;
   //    else
   //       return 1;
   // }
   // return -1;

   // if it is true that means element is not set else set
   // example
   // 13-> 1101 and if i=2
   // 1<<2 will be 100 and and of it will be 100
   return (n & (1 << i) != 0);
   // return (((n >> i) & 1) != 0);
}
bool setBit(int n, int i)
{
   return (1 << i) | n;
}
int main()
{
   // code here
   int n, i;
   cin >> n >> i;
   bool res = isBitSet(n, i);
   cout << res << endl;
   return 0;
}