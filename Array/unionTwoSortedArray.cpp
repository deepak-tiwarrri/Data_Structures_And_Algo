#include <bits/stdc++.h>
using namespace std;
vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
   //brute force approach use set data structure
   set<int> unionSet;
   for(auto &it:nums1) unionSet.insert(it);
   for(auto &it:nums2) unionSet.insert(it);
   //o(n+m)
   vector<int> unionArr(unionSet.size());
   int i=0;
   for(auto &it:unionSet){
      unionArr[i] = it;
      i++;
   }
   return unionArr;

   //optimal approach
   //Tc: O(n+m) 
   //Sc: O(n+m) extra space
   vector<int> unionArr;
   int i=0,j=0;
   int n = nums1.size();
   int m = nums2.size();
   while (i<n && j<m)
   {
     //traverse the both the array
     if(nums1[i]<=nums2[j]){
      //then check if it present in unionArray or not if not then push or if it has nothing in it
      if (unionArr.size()==0 || unionArr.back()!=nums1[i])
      {
         unionArr.push_back(nums1[i]);
      }
      i++;
     }else{
         if(unionArr.size()==0 || unionArr.back()!=nums2[j]){
            unionArr.push_back(nums2[j]);
         }
         j++;
     } 
   }
   while (i<n)
   {
      if (unionArr.size()==0 || unionArr.back()!=nums1[i])
      {
         unionArr.push_back(nums1[i]);
      }
      i++;
   }
   while(j<m){
      if(unionArr.size()==0 || unionArr.back()!=nums2[j]){
            unionArr.push_back(nums2[j]);
         }
         j++;      
   }
   return unionArr;
   
   
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   vector<int> nums1, nums2;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums1.push_back(x);
   }
   for (int j = 0; j < m; ++j)
   {
      int y;
      cin >> y;
      nums2.push_back(y);
   }
   vector<int> result = unionArray(nums1, nums2);
   for (auto &it : result)
   {
      cout << it << " ";
   }

   return 0;
}