#include<bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> &arr,int n,int d){
  //brute approach using O(d)+(n-d)+(d)
   // d = d%n;
   // int temp[n];
   // for (int i = 0; i < d; i++)
   // {
   //    temp[i] = arr[i];
   // }
   // for (int i = d; i < n; i++)
   // {
   //    arr[i-d] = arr[i];
   // }
   // for (int i = n-d; i < n;i++){
   //    arr[i] = temp[i - (n - d)];
   // }
   // return arr;
   reverse(arr.begin(),arr.begin()+d);
   reverse(arr.begin()+d,arr.end());
   reverse(arr.begin(),arr.end());
   return arr;
}
void rotateLeftKTimes(vector<int> &arr,int n,int d){
   d = d%n;
   int temp[d];
   for(int i=0;i<d;++i){
      temp[i] = arr[i];
   }
   for(int i=d;i<n;i++){
      arr[i-d] = arr[i];
   }
   for(int i=(n-d);i<n;i++){
      arr[i] = temp[i-(n-d)];
   }
}
int main(){
  int n;
  cin>>n;
  vector<int> v1;
  for(int i=0;i<n;i++){
   int x;
   cin>>x;
   v1.push_back(x);
  }
  int d;
  cin >> d;
//   vector<int> ans = rotateArray(v1, n,d);
   rotateLeftKTimes(v1, n,d);

//   for (auto &it:ans){
//      cout << it << " ";
//   }

  for (auto &it:v1){
     cout << it << " ";
  }
     return 0;
}