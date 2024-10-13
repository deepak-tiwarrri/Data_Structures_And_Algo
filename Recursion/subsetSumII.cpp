#include <bits/stdc++.h>
using namespace std;
void findSubsetDup(int indx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
   ans.push_back(ds);
   for (int i = indx; i < nums.size(); i++)
   {
      if (i > indx && nums[i] == nums[i - 1])
         continue;
      ds.push_back(nums[i]);
      findSubsetDup(i + 1, nums, ds, ans);
      ds.pop_back();
   }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
   vector<int> ds;
   vector<vector<int>> ans;
   int n = nums.size();
   sort(nums.begin(), nums.end());
   // return solution in any order
   findSubsetDup(0, nums, ds, ans);
   return ans;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr(n, 0);
   for (auto &it : arr)
      cin >> it;

   vector<vector<int>> res = subsetsWithDup(arr);
   for (auto &el : res)
   {
      for (auto &it : el)
         cout << it << " ";
      cout << endl;
   }


   return 0;
}