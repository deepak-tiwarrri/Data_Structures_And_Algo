#include <bits/stdc++.h>
using namespace std;
vector<int> sortedArrayMerge(int arr1[], int arr2[], int n, int m)
{
   // use brute force approach
   //    set<int> st;
   vector<int> mergedArray;
   //    for (int i = 0; i < n; i++)
   //    {
   //       st.insert(arr1[i]);
   //    }

   //   for (int i = 0; i < m; i++)
   //    {
   //       st.insert(arr2[i]);
   //    }
   //    for(auto &val:st){

   //       mergedArray.push_back(val);
   //    }
   //    return mergedArray;

   // code using two pointer approach TC: O(n1+n2) SC: O(n1+n2) for returning the union array
   int i = 0;
   int j = 0;
   while (i < n && j < m)
   {
      if (arr1[i] <= arr2[j])
      {
         if (mergedArray.size() == 0 || mergedArray.back() != arr1[i])
         {
            mergedArray.push_back(arr1[i]);
         }
         i++;
      }
      else
      {
         if (mergedArray.size() == 0 || mergedArray.back() != arr2[j])
         {
            mergedArray.push_back(arr2[j]);
         }
         j++;
      }
   }
   while (i < n)
   {
      if (mergedArray.size() == 0 || mergedArray.back() != arr1[i])
      {
         mergedArray.push_back(arr1[i]);
      }
      i++;
   }
   while (j < m)
   {
      if (mergedArray.size() == 0 || mergedArray.back() != arr2[j])
      {
         mergedArray.push_back(arr2[j]);
      }
      j++;
   }
   return mergedArray;
}
int main()
{
   int n, m;
   cin >> n;
   cin >> m;
   int arr1[n], arr2[m];
   for (int i = 0; i < n; i++)
   {
      cin >> arr1[i];
   }
   for (int i = 0; i < m; i++)
   {
      cin >> arr2[i];
   }
   vector<int> ans = sortedArrayMerge(arr1, arr2, n, m);
   for (auto &it : ans)
   {
      cout << it << " ";
   }
   return 0;
}