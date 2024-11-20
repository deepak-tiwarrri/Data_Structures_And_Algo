#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
   int n = nums.size();
   int cnt = 0, ele = -1;
   for (int i = 0; i < n; i++)
   {
      if (cnt == 0)
      {
         ele = nums[i];
         cnt = 1;
      }
      else if (nums[i] == ele)
      {
         cnt++;
      }
      else
      {
         cnt--;
      }
   }
   return ele;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = majorityElement(nums);
   cout << res << endl;

   return 0;
}