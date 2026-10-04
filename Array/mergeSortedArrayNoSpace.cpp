#include <bits/stdc++.h>
using namespace std;
void swapIfGreater(int arr1[], int arr2[], int indx1, int indx2)
{
   if (arr1[indx1] > arr2[indx2])
   {
      swap(arr1[indx1], arr2[indx2]);
   }
}
void mergeSortedArray(int arr1[], int arr2[], int n, int m)
{
   // int left = n - 1;
   // int right = 0;
   // while (left >= 0 && right < m)
   // {
   //    if (arr1[left] > arr2[right])
   //    {
   //       // if left is greater than swap and move both the pointer
   //       swap(arr1[left], arr2[right]);
   //       left--, right++;
   //    }
   //    else
   //    {
   //       break;
   //    }
   // }
   // sort(arr1, arr1 + n);
   // sort(arr2, arr2 + n);

   // brute force approach TC: O(2(n+m) SC: O(n+m)

   // int arr3[n + m] = {0};
   // int i = 0;
   // int j = 0;
   // int k = 0;
   // while (i < n && j < m)
   // {
   //    if (arr1[i] <= arr2[j])
   //    {
   //       arr3[k] = arr1[i];
   //       i++, k++;
   //    }
   //    else
   //    {
   //       arr3[k] = arr2[j];
   //       j++, k++;
   //    }
   // }
   // // if any one array is exhausted then
   // while (i < n)
   // {
   //    arr3[k] = arr1[i];
   //    k++, i++;
   // }
   // while (j < m)
   // {
   //    arr3[k] = arr2[j];
   //    j++;
   //    k++;
   // }
   // // now put array element back
   // for (int i = 0; i < n + m; i++)
   // {
   //    if (i < n)
   //       arr1[i] = arr3[i];
   //    else
   //       arr2[i - n] = arr3[i];
   // }

   // optimal approach uses concept of shell sort and gap method
   int len = n + m;
   int gap = (len / 2) + (len % 2);
   int left = 0;
   int right = gap + left;
   while (gap > 0)
   {
      int left = 0;
      int right = left + gap;
      while (right < len)
      {
         if (left < n && right >= n)
         {
            swapIfGreater(arr1, arr2, left, right - n);
         }
         else if (left >= n)
         {
            swapIfGreater(arr1, arr2, left - n, right - n);
         }
         else
         {
            // both in left array
            swapIfGreater(arr1, arr2, left, right);
         }
         left++, right++;
      }

      if (gap == 1)
         break;
      gap = (gap / 2) + (gap % 2);
   }
}
#include<bits/stdc++.h>
using namespace std;
void swapIfGreater(vector<long long> &arr1,vector<long long> &arr2,int ind1,int ind2){
	if(arr1[ind1]>arr2[ind2]){
		swap(arr1[ind1],arr2[ind2]);
	}
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2){
	// Write your code here.
	long long n = arr1.size();
	long long m = arr2.size();
	long long len = n+m;
	long long gap = (len%2) + (len/2);
	while(gap>0){
		int  left = 0;
		int right = gap+left;
		while(right<len){
			if(left<n && right>=n){
				swapIfGreater(arr1,arr2,left,right-n);
			}else if(left>=n){
				swapIfGreater(arr2,arr2,left-n,right-n);
			}else{
				swapIfGreater(arr1,arr1,left,right);
			}
			left++,right++;
		}
		if(gap==1) break;
		gap = (gap%2) + (gap/2);
	}
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   // int arr1[n], arr2[m];
   // for (int i = 0; i < n; i++)
   // {
   //    cin >> arr1[i];
   // }
   // for (int i = 0; i < m; i++)
   // {
   //    cin >> arr2[i];
   // }
   vector<long long> arr1,arr2;
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      arr1.push_back(x);
   }
   for(int i=0;i<m;i++){
      int x;
      cin>>x;
      arr2.push_back(x);
   }
   vector<vector<int>> ans;
   ans.push_back({1,2});
   cout<<ans.back()[1]<<endl;
   mergeTwoSortedArraysWithoutExtraSpace(arr1, arr2);
   for (int i = 0; i < n; i++)
   {
      cout << arr1[i] << " ";
   }
   cout << endl;
   for (int i = 0; i < m; i++)
   {
      cout << arr2[i] << " ";
   }

   return 0;
}