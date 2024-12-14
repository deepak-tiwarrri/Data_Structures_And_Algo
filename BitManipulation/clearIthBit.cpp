#include <bits/stdc++.h>
using namespace std;
// clear i bit
int clearBit(int n, int i)
{
   // first try to reach that position using left shift
   // then toggle it using negation ~
   // then use and ooperator
   return (n & ~(1 << i));
}

int main()
{
   // code here
   int n, i;
   cin >> n >> i;
   int res = clearBit(n, i);
   cout << res << endl;
   return 0;
}