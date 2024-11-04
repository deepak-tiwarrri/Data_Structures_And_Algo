#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
   // int minLen = INT_MAX;
   // int startIndex = -1;
   // for(int i=0;i<s.size();++i){
   //    int hash[256] = {0};
   //    for(auto &it:t) hash[it]++;
   //    int count = 0;
   //    for(int j=i;j<s.size();++j){
   //       if(hash[s[j]]) count++;
   //       hash[s[j]]--;
   //       if(count==t.size()){
   //          if((j-i+1)<minLen){
   //             minLen = j-i+1;
   //             startIndex = i;
   //          }
   //          break;
   //       }

   //    }
   // }

   int r = 0, l = 0;
   int n = s.size(), m = t.size();
   int hash[256] = {0};
   int startIndex = -1, count = 0, minLen = INT_MAX;
   for (auto &ch : t)
      hash[ch]++;
   while (r < n)
   {
      if (hash[s[r]] > 0)
         count++;
      hash[s[r]]--;
      // if count become equal to the ssecond string then
      while (count == m)
      {
         // shrink from left
         if (minLen > (r - l + 1))
         {
            minLen = r - l + 1;
            startIndex = l;
         }
         hash[s[l]]++;
         if (hash[s[l]] > 0)
            count--;
         l++;
      }
      r++;
   }
   // if startIndex is -1 that means no substring is found that has all the element in string t, in that case return empty string
   return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
}
int main()
{
   // code here
   string s, t;
   cin >> s >> t;
   string res = minWindow(s, t);
   cout << res;

   return 0;
}