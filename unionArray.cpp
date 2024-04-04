#include<bits/stdc++.h>
using namespace  std;
int main(){
   //code here
    int n,m;
    int arr1[n],arr2[m];
    cin>>n;
    cout<<endl;
    cin>>m;
    for(int i=0;i<n;i++){
      cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
      cin>>arr2[m];
    }

   for(auto &it:arr1){
      cout<<it<<" ";
   }
   cout<<endl;
   for(auto &it2:arr2){
      cout<<it2<<" ";
   }
    return 0;
}