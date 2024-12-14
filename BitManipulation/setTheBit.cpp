#include <bits/stdc++.h>
using namespace std;
// set i bit
int setBit(int n, int i)
{
   return (1 << i) ^ n;
}

int main()
{
   // code here
   int n, i;
   cin >> n >> i;
   int res = setBit(n, i);
   cout << res << endl;

   return 0;
}