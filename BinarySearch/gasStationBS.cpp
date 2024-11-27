#include <bits/stdc++.h>
using namespace std;
int numberOfStation(int distance, vector<int> &nums)
{
   int count = 0;
   for (int i = 1; i < nums.size(); i++)
   {
      int diff = ((nums[i] - nums[i - 1])) / distance;
      if ((nums[i] - nums[i - 1]) == (distance * diff))
         diff--;
      count += diff;
   }
   return count;
}
long double minimiseMaxDistance(vector<int> &nums, int k)
{
   int n = nums.size();
   // vector<int> howMany(n - 1, 0);
   // priority_queue<pair<long double, int>> pq;
   // // first store the elment in the priority queue
   // for (int i = 0; i < n - 1; ++i)
   // {
   //    pq.push({(nums[i + 1] - nums[i]), i});
   // // }
   // for (int gasStation = 1; gasStation <= k; gasStation++)
   // {
   // /* code */ brute force has TC: k*n + n which is approximately n^2, so to optimize it further we can use priority queue which store greater elment at top
   // int maxIndex = -1, maxSectionLength = -1;
   // for (int i = 0; i < nums.size(); ++i)
   // {
   //    long double diff = nums[i + 1] - nums[i];
   //    long double sectionLength = diff / (long double)(howMany[i] + 1);
   //    if (maxSectionLength < sectionLength)
   //    {
   //       maxSectionLength = sectionLength;
   //       maxIndex = i;
   //    }
   // }
   // howMany[maxIndex]++;

   // find the section length and to find that first take the section length index
   //    auto tp = pq.top();
   //    pq.pop();
   //    int secIndex = tp.second;
   //    howMany[secIndex]++;
   //    long double initDiff = nums[secIndex + 1] - nums[secIndex];
   //    long double newDiff = initDiff / (long double)(howMany[secIndex] + 1);
   //    pq.push({newDiff, secIndex});
   // }
   // return pq.top().first;

   // long double maxAns = -1;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    long double sectionLength = (nums[i + 1] - nums[i]) / (long double)(howMany[i] + 1);
   //    // now section length you know so find the max of it
   //    maxAns = max(maxAns, sectionLength);
   // }
   // return maxAns;

   // optimal approach
   long double low = 0;
   long double high = 0;
   for (int i = 0; i < n - 1; i++)
   {
      high = max(high, (long double)(nums[i + 1] - nums[i]));
   }
   long double diff = 1e-6;
   while (low - high > diff)
   {
      long double mid = (low + high) / (2.0);
      int cnt = numberOfStation(mid, nums);
      if (cnt <= k)
         high = mid;
      else
         low = mid;
   }
   return high; // becaue answer are store in high first then go the left side for further calculation
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   long double res = minimiseMaxDistance(nums, k);
   cout << res << endl;

   return 0;
}