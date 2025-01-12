#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
   // brute force appraoch
   sort(arr.begin(), arr.end());
   vector<vector<int>> ans;
   // go to each element and check if the
   // for (int i = 0; i < arr.size(); i++)
   // {
   //    int start = arr[i][0];
   //    int end = arr[i][1];
   //    if (!ans.empty() && end <= ans.back()[1])
   //    {
   //       continue;
   //    }
   //    for (int j = i + 1; j < arr.size(); j++)
   //    {  
   //       if (arr[j][0] <= end)
   //       {
   //          // update the end
   //          end = max(end, arr[j][1]);
   //       }
   //       else
   //       {
   //          break;
   //       }
   //    }
   //    ans.push_back({start, end});
   // }

   for (int i = 0; i < arr.size(); i++)
   {
      // if only push when ans is empty or first element is greater than ans back
      if (ans.empty() || ans.back()[1] < arr[i][0])
      {
         ans.push_back(arr[i]);
      }
      else
      {
         // now it's in interval we only change the ans back
         ans.back()[1] = max(ans.back()[1], arr[i][1]);
      }
   }
   return ans;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<vector<int>> nums;
   for (int i = 0; i < n; i++)
   {
      vector<int> numEle;
      for (int j = 0; j < 2; j++)
      {
         int x;
         cin >> x;
         numEle.push_back(x);
      }
      nums.push_back(numEle);
   }
   vector<vector<int>> res = mergeOverlappingIntervals(nums);
   for (auto &it : res)
   {
      for (auto &ele : it)
      {
         cout << ele << " ";
      }
      cout << endl;
   }

   return 0;
}