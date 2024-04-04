#include<bits/stdc++.h>
using namespace  std;
bool linearSearch(vector<int> &a,int num){
   for(int i=0;i<a.size();i++){
      if(num==a[i]){
         return true;
      }
   }
   return false;
}
int longestConsecutiveElements(vector<int> &a){
   // int n = a.size();
   // int longest = 1;
   // for(int i=0;i<n;i++){
   //    int x = a[i];
   //    int cnt = 1;
   //    while(linearSearch(a,x+1)==true){
   //       cnt+=1;
   //       x+=1;
   //    }
   //    longest = max(longest,cnt);
   // }
   // return longest;


   //better approach is to sort the array 
   //3 5 6 7 8
   // sort(a.begin(),a.end());
   // int lastSmaller = INT_MIN;
   // int cnt = 0;
   // int longest = 1;
   // for (int i = 0; i < a.size(); i++)
   // {
   //    if(a[i]-1==lastSmaller){
   //       cnt+=1;
   //       lastSmaller  = a[i];
   //    }else if(a[i]!=lastSmaller){
   //       cnt = 1;
   //       lastSmaller = a[i];
   //    }
   //    longest = max(longest,cnt);
   // }
   // return longest;

   unordered_set<int> stt;
   int cnt = 0;
   int longest = INT_MIN;
   for (auto &it : a)
   {
      stt.insert(it);
   }
   for (auto &it : stt)
   {
      if(stt.find(it-1)==stt.end()){
         cnt = 1;
         int x = it;
         while(stt.find(x+1)!=stt.end()){
            x+=1;
            cnt+=1;
         }
      }
      longest = max(cnt,longest);
   }
   return longest;
   
   
      
}
int main(){
   //code here
    int n;
    cin>>n;
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      v1.push_back(x);
    }
    int result = longestConsecutiveElements(v1);
    cout<<result;

    return 0;
}