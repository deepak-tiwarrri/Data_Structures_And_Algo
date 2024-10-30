#include <bits/stdc++.h>
using namespace std;
int longestNonRepeatingSubstring(string &s)
{
   // your code goes here
   //brute force appraoch using hashing and TC: O(n^2) and SC: 256
   // int maxLen = 0;
   // for(int i=0;i<s.size();i++){
   //    int hash[256] = {0};
   //    for(int j=i;j<s.size();j++){
   //       if(hash[s[j]]==1) break;
   //       maxLen = max(maxLen,j-i+1);
   //       hash[s[j]] = 1;
   //    }
   // }

   // return maxLen;
   //optimal appraoch

   int l = 0,r = 0,maxLen = 0;
   unordered_map<char,int> charMap;
   int n = s.size();
   while(r<n){
      if(charMap.find(s[r])!=charMap.end() && charMap[s[r]]>=l){
         l = charMap[s[r]] +1;
      }
      maxLen = max(maxLen,r-l+1);
      charMap[s[r]] = r;
      r++;
   }
   return maxLen;
}
int main()
{
   // code here
   string str;
   cin >> str;
   int res = longestNonRepeatingSubstring(str);
   cout << res;

   return 0;
}