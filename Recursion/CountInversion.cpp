#include<bits/stdc++.h>
using namespace  std;

int mergeArr(int low,int mid,int high,vector<int> &arr,int n){
   int left = low;
   int right = mid+1;
   int cnt = 0;
   vector<int> temp;
   while(left<=mid && right<=high){
      if(arr[left]<=arr[right]){
         temp.push_back(arr[left]);
         left++;
      }else{
         temp.push_back(arr[right]);
         cnt+= (mid-left+1);
         right++;
      }
   }
   while(left<=mid){
      temp.push_back(arr[left]);
      left++;
   }
   while(right<=high){
      temp.push_back(arr[right]);
      right++;
   }
   for(int i=low;i<=high;i++){
      arr[i] = temp[i-low];
   }
   return cnt;
}
int mergeSort(int low,int high,vector<int> &arr,int n){
   int cnt = 0;
   if(low>=high) return cnt;
   int mid = (high-low)/2 + low;
   cnt+= mergeSort(low,mid,arr,n);
   cnt+= mergeSort(mid+1,high,arr,n);
   cnt+= mergeArr(low,mid,high,arr,n);
   return cnt;
}
int countInversion(vector<int> &arr,int n){
   return mergeSort(0,n-1,arr,n);
}
int main(){
   //code here
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr){
      cin>>it;
    }
    //array printing 
    int res = countInversion(arr,n);
    cout<<res<<endl;

    cout<<"printed array after inversion"<<endl;
    for(auto &it:arr){
      cout<<it<<" ";
    }
    return 0;
}