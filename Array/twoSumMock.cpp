#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
   //brute is n^2
   //better is using hashmap

}
int main()
{
   // code here
   int n,target;
   cin>>n>>target;
   vector<int> nums;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin>>x;
      nums.push_back(x);
   }
   vector<int> res = twoSum(nums,target);
   for(auto &it:res) cout<<it<<" ";
   
   return 0;
}