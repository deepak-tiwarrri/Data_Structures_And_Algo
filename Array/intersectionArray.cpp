
#include <bits/stdc++.h>
using namespace std;

vector<int> interSectionArray(vector<int> &nums1, vector<int> &nums2, int n, int m)
{
   // int visited[m] = {0};
   // vector<int> ans;
   // for(int i=0;i<n;i++){
   //    for (int j = 0; j < m;j++){
   //       if (nums1[i]==nums2[j] && visited[j]==0)
   //       {
   //          ans.push_back(nums1[i]);
   //          visited[j] = 1;
   //          break;
   //       }
   //       if(nums2[j]>nums1[i])
   //          break;
   //    }

   // }
   // return ans;
   vector<int> ans;
   int visited[m] = {0};
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (nums1[i] == nums2[j] && visited[j] == 0)
         {
            ans.push_back(nums1[i]);
            // not visited should be mark 1
            visited[j] = 1;
            break;
         }
         if (nums2[j] > nums1[i])
            break;
      }
   }
   return ans;

   // int i=0;
   // int j=0;
   // while (i<n && j<m)
   // {
   //    if(nums1[i]<nums2[j])
   //       i++;
   //    else if(nums2[j]<nums1[i])
   //       j++;
   //    else {
   //       ans.push_back(nums1[i]);
   //       i++;
   //       j++;
   //    }
   // }
   // return ans;
}
int main()
{

   int n,m;
   cin>>n>>m;
   vector<int> nums1,nums2;
   for(int i=0;i<n;++i){
      int x;
      cin>>x;
      nums1.push_back(x);
   }
   for(int j=0;j<m;j++){
      int y;
      cin>>y;
      nums2.push_back(y);
   }
   
   return 0;
}