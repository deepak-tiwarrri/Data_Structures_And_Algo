#include<bits/stdc++.h>
using namespace  std;
void mergeSortedArray(int arr1[],int arr2[],int n,int m){
   // int left = n-1;
   // int right = 0;
   // while(left>=0 && right <m){
   //    if(arr1[left]>arr2[right]){
   //       swap(arr1[left],arr2[right]);
   //       left--,right++;
         
   //    }else break;
   // }
   // sort(arr1,arr1+n);
   // sort(arr2,arr2+m);

//brute force approach TC: O(2(n+m) SC: O(n+m)

   int arr3[n+m];
   int index = 0;
   int left = 0,right = 0;
   while(left<n && right<m){
      if(arr1[left]<=arr2[right]){
         arr3[index++] = arr1[left++];
      }else{
         arr3[index++] = arr2[right++];
      }
   }
   while(left<n){
      arr3[index++] = arr1[left++];
   }
   while(right<m){
      arr3[index++] = arr2[right++];
   }
   for(int i=0;i<(n+m);i++){
      if(i<n) arr1[i] = arr3[i];
      else arr2[i-n] = arr3[i];
   }
}
int main(){
   //code here
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for (int i = 0; i < n; i++)
    {
      cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
      cin>>arr2[i];
    }
    
    mergeSortedArray(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
      cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
      cout<<arr2[i]<<" ";
    }
    

    return 0;
}