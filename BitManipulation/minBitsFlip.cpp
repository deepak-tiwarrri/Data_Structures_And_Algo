#include <bits/stdc++.h>
using namespace std;
int minBitsFlip(int start, int goal)
{
   int ans = start ^ goal;
   int count = 0;
   while (ans > 0)
   {
      ans = (ans ^ (ans - 1));
      count++;
   }
   return count;
}
int main()
{
   // code here
   int start, goal;
   cin >> start >> goal;
   int res = minBitsFlip(start, goal);
   cout << res << endl;

   return 0;
}