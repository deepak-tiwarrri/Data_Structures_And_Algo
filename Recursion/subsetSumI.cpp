#include <bits/stdc++.h>
using namespace std;
// void findSubsetSum(int indx, vector<int> &arr, int n, vector<int> &ds, int sum)
// {
//    if(indx==n) {
//       ds.push_back(sum);
//       return;
//    }
//    findSubsetSum(indx+1,arr,n,ds,sum+arr[indx]);
//    findSubsetSum(indx+1,arr,n,ds,sum);
// }

// vector<int> subsetSums(vector<int> &arr, int n)
// {
//    vector<int> ds;
//    findSubsetSum(0, arr, n, ds, 0);
//    sort(ds.begin(),ds.end());
//    return ds;
// }

void findSubsetSum(int indx,int sum,vector<int> &arr,int n,vector<int> &ds){
   if(indx==n){
      ds.push_back(sum);
      return;      
   }
   findSubsetSum(indx+1,sum+arr[indx],arr,n,ds);
   //if not pick then sum will be same
   findSubsetSum(indx+1,sum,arr,n,ds);
}
vector<int> subsetSums(vector<int> &arr,int n){
   vector<int> ds;
   // sort(arr.begin(),arr.end());
   findSubsetSum(0,0,arr,n,ds);
   sort(ds.begin(),ds.end());
   return ds;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr(n, 0);
   for (auto &it : arr)
      cin >> it;

   vector<int> res = subsetSums(arr, n);
   for (auto &el : res)
      cout << el << " ";

   return 0;
}