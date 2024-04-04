#include<bits/stdc++.h>
using namespace  std;
void reverseArray(int arr[],int &n){
   reverse(arr,arr+(n-1));
   reverse(arr+(n-1),arr+n);
   reverse(arr,arr+n);
}
int main(){
   //code here
    int n;
    cin>>n;
    int arr[n];

   for (int i = 0; i < n; i++)
   {
      cin>>arr[i];
   }
   cout<<"reversed array is "<<endl;
   reverseArray(arr,n);
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;

    return 0;
}