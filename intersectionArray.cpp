// #include<bits/stdc++.h>
// using namespace  std;
// vector<int> interSectionArray(int arr1[],int arr2[],int n,int m){
//    int i=0;
//    int j=0;
//    vector<int> ans;
//    while(i<n && j<m){
//       if(arr1[i]<arr2[j]) i++;
//       else if(arr2[j]<arr1[i]) j++;
//       else {
//          ans.push_back(arr1[i]);
//          i++;
//          j++;
//       }
//    }
//    return ans;
// }
// int main(){
//    //code here
//     int n, m;
//    cin >> n;
//    cin >> m;
//    int arr1[n], arr2[m];
//    for (int i = 0; i < n;i++){
//       cin >> arr1[i];
//    }
//    for (int i = 0; i < m;i++){
//       cin >> arr2[i];
//    }
//    vector<int> ans = interSectionArray(arr1, arr2, n, m);
//    for(auto &it:ans){
//       cout << it << " ";
//    }

//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

vector<int> interSectionArray(vector<int> &arr1,vector<int> &arr2,int n,int m){
   // int visited[m] = {0};
   vector<int> ans;
   // for(int i=0;i<n;i++){
   //    for (int j = 0; j < m;j++){
   //       if (arr1[i]==arr2[j] && visited[j]==0)
   //       {
   //          ans.push_back(arr1[i]);
   //          visited[j] = 1;
   //          break;
   //       }
   //       if(arr2[j]>arr1[i])
   //          break;
   //    }
      
   // }
   // return ans;

   int i=0;
   int j=0;
   while (i<n && j<m)
   {
      if(arr1[i]<arr2[j])
         i++;
      else if(arr2[j]<arr1[i])
         j++;
      else {
         ans.push_back(arr1[i]);
         i++;
         j++;
      }
   }
   return ans;
}
int main(){
   int n, m;
   cin >> n >> m;
   vector<int> arr1;
   vector<int> arr2;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin>>x;
      arr1.push_back(x);
   }
   for (int i = 0; i < m; i++)
   { 
      int x;
      cin>>x;
      arr1.push_back(x);
   }
   vector<int> ans = interSectionArray(arr1, arr2, n, m);
   for (auto &it : ans)
   {
      cout << it << " ";
   }
    
  return 0;
}