#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
   // brute force appraoch TC: O(n^2)
   // int n = nums.size();
   // int repeating = -1, missing = -1;
   // for (int i = 1; i <= n; i++)
   // {
   //    int count = 0;
   //    for (int j = 0; j < n; j++)
   //    {
   //       if (nums[j] == i)
   //          count++;
   //    }
   //    if (count == 2)
   //       repeating = i;
   //    else if (count == 0)
   //       missing = i;
   //    if (repeating != -1 && missing != -1)
   //       break;
   // }
   // return {repeating, missing};

   // in better we will use concept of hashing
   //  make a hash and increment the count
   // int repeating = -1, missing = -1;
   // int n = nums.size();
   // int hash[n + 1] = {0};
   // for (int i = 0; i < n; i++)
   // {
   //    hash[nums[i]]++;
   // }
   // for (int i = 1; i <= n; i++)
   // {
   //    if (hash[i] == 2)
   //       repeating = i;
   //    else if (hash[i] == 0)
   //       missing = i;
   // }
   // return {repeating, missing};

   // optimal usiing maths and there is another optimmal using bit manipulation and xor
   long long n = nums.size();
   long long repeating = -1, missing = -1;
   long long SN = (n * (n + 1)) / 2;                // sum of first n natural number
   long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; // sum of first n^2 natural number
   long long S = 0, S2 = 0;
   for (int i = 0; i < n; i++)
   {
      // sum of each number in array
      S += nums[i];
      // sum of square of number in array
      S2 += ((long long)nums[i] * (long long)nums[i]);
   }
   long long val1 = S - SN;
   long long val2 = S2 - S2N;
   val2 = val2 / val1;

   repeating = (val1 + val2) / 2;
   missing = (repeating - val1);
   return {static_cast<int>(repeating), static_cast<int>(missing)};
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
   vector<int> res = findMissingRepeatingNumbers(nums);
   for (auto &it : res)
   {
      cout << it << " ";
   }

   return 0;
}