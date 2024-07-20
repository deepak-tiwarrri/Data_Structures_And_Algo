#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string &s)
{
   //brute force approach
   // int hash[255] = {-1};
   int n = s.size();
   int maxLen = 0;
   // for(int i=0;i<n;i++){
   //    for(int j=i;j<n;j++){
   //       if(hash[s[j]]==-1){
   //          maxLen = max(maxLen, j-i+1);
   //          hash[s[j]] = 1;
   //       }else break;
   //    }
   // }
   //optimmal approach
   // unordered_set<int> stt;
   // while(r<n){
   //    if(stt.find(s[r])!=stt.end()){
   //       //if duplicate element are present
   //       while(l<r && stt.find(s[l])!=stt.end()) {
   //          stt.erase(s[l]);
   //          l++;
   //       }
   //    }
   //    stt.insert(s[r]);
   //    maxLen = max(maxLen,r-l+1);
   //    r++;
   // }
   // int l=0,r = 0;
   // unordered_map<char,int> mpp;
   // while (r<n)
   // {
   //    if(mpp.find(s[r])!=mpp.end()){
        
   //      l = mpp[s[r]]+1;
   //    }
   //    mpp[s[r]] = r;
   //    maxLen = max(maxLen,r-l+1);
   //    r++;
   // }
   
   // return maxLen;
   int l=0,r = 0;
   vector<int> hash(256,-1);
   while (r<n)
   {
      if(hash[s[r]]!=-1) l = max(l,hash[s[r]]+1);
      hash[s[r]] = r;
      maxLen = max(maxLen,r-l+1);
      r++;
   }
   return maxLen;
}
int main()
{
   // code here
   string s;
   cin >> s;
   int result = lengthOfLongestSubstring(s);
   cout << result;

   return 0;
}