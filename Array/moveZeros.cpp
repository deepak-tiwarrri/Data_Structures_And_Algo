#include <bits/stdc++.h>
using namespace std;
void moveZeros(vector<int> &arr,int n){
   //create a temp array
  vector<int> temp;
  for(auto &it:arr){
   if(it!=0) temp.push_back(it);
  }
   //1 3 12
   int newSize = temp.size();
   for(int i=0;i<newSize;i++){
      arr[i] = temp[i];
   }
   for(int i=newSize;i<n;i++){
      arr[i] = 0;
   }

   // optimal approach
   int j= -1;
   for(int i=0;i<n;i++){
      if(arr[i]==0){
         j = i;
         break;
      }
   }
   if(j==-1) return;
   for(int i=j+1;i<n;i++){
      if(arr[i]!=0){
         swap(arr[i],arr[j]);
         j++;
      }
   }

   //using while loop
   int j= -1;
   int i=0;
   while(i<n){
      if(arr[i]==0){
         j = i;
         break;
      }
   }
   i = j+1;
   while(i<n){
      if(arr[i]!=0){
         swap(arr[i],arr[j]);
         j++;
      }
      i++;
   }

}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> v1;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      v1.push_back(x);
   }
   moveZeros(v1,n);
   for(auto &it:v1){
      cout<<it<<" ";
   }
   return 0;
}