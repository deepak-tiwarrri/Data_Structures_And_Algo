#include<bits/stdc++.h>
using namespace  std;


class solution
{
public:
vector<int> insertionSort(vector<int> arr)
{
   int n = arr.size();
   for(int i=0;i<n-1;i++)
   {
      for(int j=i+1;j<n;j++)
      {
         if(arr[i]>arr[j])
         {
            swap(arr[i],arr[j]);
         }
      }
   }
   return arr;
}

   //   **selection sort**
// vector<int> selectionSort(vector<int> arr)
// {
//    int n = arr.size();
//    for(int i=0;i<n-1;i++)
//    {
//       for(int j=i+1;j<n;j++)
//       {
//          if(arr[i]>arr[j])
//          {
//             swap(arr[i],arr[j]);
//          }
//       }
//    }
//    return arr;
// }
};


int main(){
   //code here
    int n;cin>>n; 
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
      int a;
      cin>>a;
      arr.push_back(a);
    }
    
    solution s;
    vector<int> ans = s.insertionSort(arr);
   //  vector<int> ans = s.selectionSort(arr);
    for(auto it : ans)
    {
      cout<<it<<" ";
    }
    return 0;
}