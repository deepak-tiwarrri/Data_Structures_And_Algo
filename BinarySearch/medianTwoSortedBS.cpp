#include <bits/stdc++.h>
using namespace std;
double median(vector<int> &arr1, vector<int> &arr2)
{
   // int n = arr1.size(), m = arr2.size();
   // int i = 0, j = 0;
   // vector<int> ans;
   // while (i < n && j < m)
   // {
   //    if (arr1[i] <= arr2[j])
   //       ans.push_back(arr1[i++]);
   //    else
   //       ans.push_back(arr2[j++]);
   // }
   // while (i < n)
   //    ans.push_back(arr1[i++]);
   // while (j < m)
   //    ans.push_back(arr2[j++]);
   // int k = n + m;
   // if (k % 2 == 1) // if ans is odd return
   //    return ans[k / 2];
   // return (double)((double)ans[k / 2] + (double)ans[k / 2 - 1]) / 2.0;

   // int n1 = arr1.size(), n2 = arr2.size();
   // int n = n1 + n2;
   // int cnt = 0;
   // int ele1 = -1, ele2 = -1;
   // int i = 0, j = 0;
   // int ind1 = n / 2;
   // int ind2 = ind1 - 1; // ind1 will be
   // while (i < n1 && j < n2)
   // {
   //    if (arr1[i] < arr2[j])
   //    {
   //       if (cnt == ind1)
   //          ele1 = arr1[i];
   //       if (cnt == ind2)
   //          ele2 = arr1[i];
   //       i++;
   //       cnt++;
   //    }
   //    else
   //    {
   //       if (cnt == ind1)
   //          ele1 = arr2[j];
   //       if (cnt == ind2)
   //          ele2 = arr2[j];
   //       j++;
   //       cnt++;
   //    }
   // }
   // while (i < n1)
   // {
   //    if (cnt == ind1)
   //       ele1 = arr1[i];
   //    if (cnt == ind2)
   //       ele2 = arr1[i];
   //    i++;
   //    cnt++;
   // }
   // while (j < n2)
   // {
   //    if (cnt == ind1)
   //       ele1 = arr2[j];
   //    if (cnt == ind2)
   //       ele2 = arr2[j];
   //    j++;
   //    cnt++;
   // }
   // if (n % 2 == 1) // if odd directly return ele2
   // {
   //    return (double)ele2;
   // }
   // return (double)((double)(ele1 + ele2) / 2.0);
   int n1 = arr1.size();
   int n2 = arr2.size();
   if(n1>n2) return median(arr2,arr1);
   //first array is smaller consider like this and second is bigger

   int n = (n1+n2);
 
   //left half length [1,2,3,4,5,6] here length of the left is 3
   int left = (n1+n2+1)/2; // 3
   int low = 0, high = n1;//sorter array length
   while(low<=high){
      int mid1 = (low+high)>>1; //1
      int mid2 = left-mid1; //3-1 = 2
      int l1 = INT_MIN,l2 = INT_MIN;
      int r1 = INT_MAX,r2 = INT_MAX;

      if(mid1<n1) r1 = arr1[mid1];
      if(mid2<n2) r2 = arr2[mid2];
      if(mid1-1>=0) l1 = arr1[mid1-1];
      if(mid2-1>=0) l2 = arr2[mid2-1];

      if(l1<=r2 && l2<=r1){
         if(n%2==1) return max(l1,l2);
         return (double)((max(l1,l2)+min(r1,r2))/2.0);
      }else if(l1>r2) high  = mid1-1;
      else if(l2>r1) low = mid1+1;
   }
   return 0;
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
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

   double res = median(arr1, arr2);
   cout << res << endl;
   return 0;
}