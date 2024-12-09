#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
   // brute will be to use three loop
   // sort the nums and store in set<vector<int>>
   // and then return it
   // set<vector<int>> stt;
   // for (int i = 0; i < nums.size(); i++)
   // {
   //    for (int j = i + 1; j < nums.size(); j++)
   //    {
   //       for (int k = j + 1; k < nums.size(); k++)
   //       {
   //          if (nums[i] + nums[j] + nums[k] == 0)
   //          {
   //             vector<int> temp = {nums[i], nums[j], nums[k]};
   //             sort(temp.begin(), temp.end());
   //             stt.insert(temp);
   //          }
   //       }
   //    }
   // }
   // vector<vector<int>> ans(stt.begin(), stt.end());
   // return ans;

   // better appraoch takes O(n2) but SC: O(n) approximately
   int n = nums.size();
   // set<vector<int>> st;
   // for (int i = 0; i < n; i++)
   // {
   //    unordered_set<int> stt;
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       int third = -(nums[i] + nums[j]);
   //       if (stt.find(third) != stt.end())
   //       {
   //          vector<int> temp = {nums[i], nums[j], third};
   //          sort(temp.begin(), temp.end());
   //          st.insert(temp);
   //       }
   //       stt.insert(nums[j]);
   //    }
   // }
   // vector<vector<int>> ans(st.begin(), st.end());
   // return ans;

   // optimal approach using two pointer
   vector<vector<int>> ans;
   // sort the array, don't forget to sort it
   sort(nums.begin(), nums.end());
   for (int i = 0; i < n; i++)
   {
      // if is catch use if not while loop here
      //*** */
      if (i != 0 && nums[i] == nums[i - 1])
         continue;
      int j = i + 1;
      int k = n - 1;
      while (j < k)
      {

         if (nums[j] + nums[i] + nums[k] < 0)
         {
            j++;
         }
         else if (nums[i] + nums[j] + nums[k] > 0)
         {
            k--;
         }
         else
         {
            while (j < k && nums[j] == nums[j - 1])
               j++;
            while (j < k && nums[k] == nums[k + 1])
               k--;
            vector<int> temp = {nums[i], nums[j], nums[k]};
            ans.push_back(temp);
            j++;
            k--;
         }
      }
   }
   return ans;
}

int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      ans.push_back(x);
   }
   vector<vector<int>> res = threeSum(ans);
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