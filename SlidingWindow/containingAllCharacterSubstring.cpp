#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string &s)
{
   int cnt = 0;
   int n = s.size();
   // brute force appraoch using O(n2) and O(1)
   //  for (int i = 0; i < s.size(); i++)
   //  {
   //     int hash[3] = {0};
   //     for (int j = i; j < s.size(); j++)
   //     {
   //        hash[s[j] - 'a'] = 1;
   //        if (hash[0] + hash[1] + hash[2] == 3)
   //        {
   //           cnt = cnt + (n - j);
   //           break;
   //        }
   //     }
   //  }
   int lastSeen[3] = {-1, -1, -1};
   for (int i = 0; i < n; i++)
   {
      lastSeen[s[i] - 'a'] = i;
      // if(lastSeen[0]!=-1 && lastSeen[1]!=-1&& lastSeen[2]!=-1){
      cnt = cnt + (min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1);
      // }
   }
   return cnt;
}
int characterReplacement(string s, int k)
{
   int maxFreq=INT_MIN,maxLen =0;
   // for(int i=0;i<s.size();i++){
   //    int hash[26]={0};
   //    for(int j=i;j<s.size();j++){
   //       hash[s[j]-'A']++;
   //       maxFreq = max(hash[s[j]-'A'],maxFreq);
   //       int changes = (j-i+1)- maxFreq;
   //       if(changes<=k){
   //          maxLen = max(maxLen,j-i+1);
   //       }
   //       else break;
   //    }
   // }
   int r=0,l=0;
   int hash[26] = {0};
   while(r<s.size()){
      hash[s[r]-'A']++;
      maxFreq = max(hash[s[r]-'A'],maxFreq);
      // int changes = (r-l+1)-maxFreq;
      if((r-l+1)-maxFreq >k){
         hash[s[l]-'A']--;
         // maxFreq = max(hash[s[r]-'A'],maxFreq);
         // maxFreq = INT_MIN;
         // for(int i=0;i<26;i++) maxFreq = max(maxFreq,hash[i]);
         l++;
      }
      // if((r-l+1)-maxFreq <=k)
      maxLen = max(maxLen,r-l+1);
      r++;
   }
   return maxLen;
}

int main()
{
   // code here
   string s;
   int k;
   cin >> s>>k;
   // int res = numberOfSubstrings(s,k);
   int res = characterReplacement(s,k);
   cout << res;

   return 0;
}