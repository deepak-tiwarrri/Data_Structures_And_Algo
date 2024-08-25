#include <bits/stdc++.h>
// #include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
   //brute force approach
   // vector<int> ans(arr.size() - k + 1);
   // for (int i = 0; i <= arr.size() - k; i++)
   // {
   //    int maxi = arr[i];
   //    for (int j = i; j <= i + k - 1; j++)
   //    {
   //       maxi = max(maxi, arr[j]);
   //    }
   //    ans[i] = maxi;
   // }
   // return ans;
   int n= arr.size();
   vector<int> ans;
   deque<int> dq;
   for(int i=0;i<n;i++){
      if(!dq.empty() && dq.front()<=i-k){
         dq.pop_front();
      }
      while(!dq.empty() && arr[dq.back()]<=arr[i]) {
         dq.pop_back();
      }
      dq.push_back(i);
      if(i>=k-1) ans.push_back(arr[dq.front()]);
   }
   return ans;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> arr;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   vector<int> res = maxSlidingWindow(arr, k);
   for (auto &it : res)
      cout << it << " ";

   return 0;
}