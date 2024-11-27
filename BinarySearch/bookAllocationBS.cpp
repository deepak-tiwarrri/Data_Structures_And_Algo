#include <bits/stdc++.h>
using namespace std;
int numberOfStudent(vector<int> &nums, int numberOfPages)
{
   // find the number of student allocated
   int countOfStudent = 1;
   int lastStudent = nums[0];
   for (int i = 1; i < nums.size(); i++)
   {
      if (nums[i] + lastStudent <= numberOfPages)
      {
         // then we can add
         lastStudent += nums[i];
      }
      else
      {
         // it means we can place the student
         countOfStudent++;
         lastStudent = nums[i];
      }
   }
   return countOfStudent;
}
int findPages(vector<int> &nums, int m)
{
   if (m > nums.size())
      return -1;
   int low = *max_element(nums.begin(), nums.end());
   int high = accumulate(nums.begin(), nums.end(), 0);

   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (numberOfStudent(nums, mid) <= m)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return low;
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = findPages(nums, m);
   cout << res << endl;

   return 0;
}