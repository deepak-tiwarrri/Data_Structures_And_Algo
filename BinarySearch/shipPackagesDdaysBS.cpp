#include <bits/stdc++.h>
using namespace std;
int numberOfDays(vector<int> &weights, int capacity, int d)
{
   int day = 1;
   int sumOfWeight = 0;
   for (int i = 0; i < weights.size(); i++)
   {
      if (sumOfWeight + weights[i] <= capacity)
      {
         // if it is less than capacity sum it up
         sumOfWeight += weights[i];
      }
      else
      {
         // now load it and increase the day count also capacity become new weight
         day++;
         sumOfWeight = weights[i];
      }
   }
   return day;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
   // find the minimum capacity to ship within d days
   int low = *max_element(weights.begin(), weights.end());
   int high = accumulate(weights.begin(), weights.end(), 0);

   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      if (numberOfDays(weights, mid, d) <= d)
      {
         // if it is less than d it means possible, so find the least and go to left side
         high = mid - 1;
      }
      else
         low = mid + 1;
   }
   return low;
}
int main()
{
   // code here
   int n, d;
   cin >> n >> d;
   vector<int> weights;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      weights.push_back(x);
   }
   int res = leastWeightCapacity(weights, d);
   cout << res << endl;

   return 0;
}