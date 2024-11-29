#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
   if(n>m) kthElement(arr2,arr1,m,n,k);

   int low = max(0,k-n);
   int high = min(m,k);
   int left = k;
   while(low<=high){
      int mid1 = (low+high)>>1;
      int mid2 = left-mid1;
      int l1 = INT_MIN,l2 = INT_MIN;
      int r1 = INT_MAX,r2 = INT_MAX;

      if(mid1<n) r1 = arr1[mid1];
      if(mid2<m) r2 = arr2[mid2];

      if(mid1-1>=0) l1 = arr1[mid1-1];
      if(mid2-1>=0) l2 = arr2[mid2-1];

      if(l1<=r2 && l2<=r1) return max(l1,l2);
      else if(l1>r2) high = mid1-1;
      else low = mid1+1;
   }
   return 0;
}
int main()
{
   // code here
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> arr1, arr2;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr1.push_back(x);
   }
   for (int i = 0; i < m; i++)
   {
      int y;
      cin >> y;
      arr2.push_back(y);
   }

   int res = kthElement(arr1, arr2, n, m, k);
   cout << res << endl;

   return 0;
}