#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> a, int b)
{
   // Write your code here
   //x = xr^k;
   unordered_map<int,int> mpp;
   int xr = 0;
   int cnt = 0;
   mpp[xr]++;
   for(int i=0;i<a.size();i++){
      xr = xr^a[i];
      int x = xr^b;
      cnt+=mpp[x];
      mpp[xr]++;
   }
   return cnt;
}
int main()
{
   // code here
   int n, k;
   cin >> n >> k;
   vector<int> a;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin>>x;
      a.push_back(x);
   }
   int result = subarraysWithSumK(a,k);
   cout<<result;
   

   return 0;
}