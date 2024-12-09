#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
   // brute force approach
   // set<vector<int>> st;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    for (int j = i + 1; j < nums.size(); j++)
   //    {
   //       for (int k = j + 1; k < nums.size(); k++)
   //       {
   //          for (int l = k + 1; l < nums.size(); l++)
   //          {
   //             long long sum = nums[i] + nums[j] + nums[k] + nums[l];
   //             if (sum == target)
   //             {
   //                vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
   //                // sorting if they have multiple 4sum
   //                sort(temp.begin(), temp.end());
   //                st.insert(temp);
   //                // ans.push_back(temp);
   //             }
   //          }
   //       }
   //    }
   // }
   // vector<vector<int>> ans(st.begin(), st.end());
   // return ans;

   // better approach using hashing
   // set<vector<int>> tripletSet;
   // int n = nums.size();
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       unordered_set<long long> hashSet;
   //       for (int k = j + 1; k < n; k++)
   //       {
   //          long long sum = nums[i] + nums[j];
   //          sum += nums[k];
   //          long long fourth = target - sum;
   //          if (hashSet.find(fourth) != hashSet.end())
   //          {
   //             vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
   //             sort(temp.begin(), temp.end());
   //             tripletSet.insert(temp);
   //          }
   //          // insert element between i, j and k
   //          hashSet.insert(nums[k]);
   //       }
   //    }
   // }
   // vector<vector<int>> res(tripletSet.begin(), tripletSet.end());
   // return res;

   sort(nums.begin(), nums.end());
   vector<vector<int>> ans;
   for (int i = 0; i < nums.size(); i++)
   {
      if (i != 0 && nums[i] == nums[i - 1])
         continue;
      for (int j = i + 1; j < nums.size(); j++)
      {
         if (j > i + 1 && j != i && nums[j] == nums[j - 1])
            continue;
         int k = j + 1;
         int m = nums.size() - 1;
         while (k < m)
         {
            long long sum = nums[i] + nums[j];
            sum +=nums[k] + nums[m];
            if (sum > target)
            {
               m--;
            }
            else if (sum < target)
               k++;
            else
            {
               vector<int> temp = {nums[i], nums[j], nums[k], nums[m]};
               ans.push_back(temp);
               k++;
               m--;
               while (k < m && nums[k] == nums[k - 1])
                  k++;
               while (k < m && nums[m] == nums[m + 1])
                  m--;
            }
         }
      }
   }
   return ans;
}

int main()
{
   // code here
   int n, target;
   cin >> n >> target;
   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      ans.push_back(x);
   }
   vector<vector<int>> res = fourSum(ans, target);
   for (auto &it : res)
   {
      for (auto &it1 : it)
      {
         cout << it1 << " ";
      }
      cout << endl;
   }

   return 0;
}