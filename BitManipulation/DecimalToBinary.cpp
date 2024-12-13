#include <bits/stdc++.h>
using namespace std;
string decimalToBinary(int num)
{
   // Tc: O(logn) SC: O(logN)
   string res = "";
   while (num > 0)
   {
      int rem = num % 2;
      if (rem == 1)
         res += '1';
      else
         res += '0';
      num = num / 2;
   }
   reverse(res.begin(), res.end());
   return res;
}

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

// set i bit
int setBit(int n, int i)
{
   return (1 << i) ^ n;
}

// clear i bit
int clearBit(int n, int i)
{
   // first try to reach that position using left shift
   // then toggle it using negation ~
   // then use and ooperator
   return (n & ~(1 << i));
}

// toggle the bit
int toggleBit(int n, int i)
{
   return (n ^ (1 << i));
}

// remove the last set bit
int removeLastSetBit(int n)
{
   return n & (n - 1);
}
bool checkIfPowerOf2(int n)
{
   return (n > 0) && (n & (n - 1)) == 0;
}

int main()
{
   // code here
   int decimalNumber;
   cin >> decimalNumber;
   // string res = decimalToBinary(decimalNumber);
   // string n;
   // cin >> n;
   // int res = binaryToDecimal(n);
   // cout << res << endl;
   // int res = clearBit(decimalNumber, 2);
   // int res = toggleBit(decimalNumber, 1);
   // int res = removeLastSetBit(decimalNumber);
   // bool res = checkIfPowerOf2(decimalNumber);
   // if (res)
   //    cout << "true";
   // else
   //    cout << "false";

   return 0;
}