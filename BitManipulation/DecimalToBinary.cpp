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
   // return (n & (1 << i) != 0);
   // return (((n >> i) & 1) != 0);
   return (1 << i) | n;
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
   int decimalNumber;
   cin >> decimalNumber;
   // string res = decimalToBinary(decimalNumber);
   // string n;
   // cin >> n;
   // int res = binaryToDecimal(n);
   // cout << res << endl;
   // bool res = isBitSet(decimalNumber, 3);
   // int res = clearBit(decimalNumber, 2);
   // int res = toggleBit(decimalNumber, 1);
   // int res = removeLastSetBit(decimalNumber);
   // bool res = checkIfPowerOf2(decimalNumber);
   // if (res)
   //    cout << "true";
   // else
   //    cout << "false";

   int res = countSetBit(decimalNumber);
   cout << res << endl;

   return 0;
}