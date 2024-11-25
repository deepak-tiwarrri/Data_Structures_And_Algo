#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
   int i = 0;
   string ans;
   int n = s.size();
   while (i < n)
   {
      while (i < n && s[i] == ' ')
         i++;
      if (i >= n)
         break;
      int j = i + 1;
      while (j < n && s[j] != ' ')
         j++;
      string words = s.substr(i, j - i);
      if (ans.length() == 0)
         ans = words;
      else
         ans = words + " " + ans;
      i = j + 1;
   }
   return ans;
}
bool validShuffleOrNot(string s1, string s2, string result)
{
   // s1 = xy //s2 = 12 then res = x1y2 then valid
   // if res = 2y1x is also valid so same length and all the
   // value should be present
   if (s1.size() + s2.size() != result.size())
      return false;
   int i = 0, j = 0, k = 0;
   // i for s1,j for s2, and k for res
   while (k < result.size())
   {
      if (i < s1.size() && s1[i] == result[k])
         i++;
      else if (j < s2.size() && s2[j] == result[k])
         j++;
      else
         return false;
      k++;
   }
   if (i < s1.size() || j < s2.size())
      return false;
   return true;
}
bool isPalindrome(string s)
{
   int left = 0;
   int right = s.size() - 1;
   while (left < right)
   {
      if (s[left] != s[right])
         return false;
      left++;
      right--;
   }
   return true;
}
int dp[1001][1001];
bool solve(string &s, int l, int r)
{
   if (l >= r)
      return 1;
   if (dp[l][r] != -1)
      return dp[l][r];
   if (s[l] == s[r])
      return dp[l][r] = solve(s, l + 1, r - 1);
   return dp[l][r] = false;
}
string longestPalindromicSub(string s)
{
   // if(s.length()<=1) return s;
   // int max_len = 1;
   // string  max_str = s.substr(0,1);
   // for(int i=0;i<s.length();++i){
   //    for(int j=i+max_len;j<=s.length();++j){
   //       if(j-i>max_len && isPalindrome(s.substr(i,j-i))){
   //          max_len = j-i;
   //          max_str = s.substr(i,j-i);
   //       }
   //    }
   // }
   // return max_str;

   // dp solution
   // int n = s.length();
   // int maxLen = INT_MIN;
   // int startIndex = 0;
   // memset(dp,-1,sizeof(dp));
   // for(int i=0;i<n;++i){
   //    for(int j=i;j<n;++j){
   //       if(solve(s,i,j)){
   //          if(j-i+1>maxLen){
   //             startIndex = i;
   //             maxLen = j-i+1;
   //          }
   //       }
   //    }
   // }
   // return s.substr(startIndex,maxLen);
   int maxLen = INT_MIN;
   int n = s.size();
   if (s.length() <= 1)
      return s;
   auto expand_from_center = [&](int left, int right)
   {
      while (left >= 0 && right < s.length() && s[left] == s[right])
      {
         left--;
         right++;
      }
      return s.substr(left + 1, right - left - 1);
   };
   string max_str = s.substr(0, 1);
   for (int i = 0; i < s.length() - 1; i++)
   {
      string odd = expand_from_center(i, i);
      string even = expand_from_center(i, i + 1);
      if (odd.length() > max_str.length())
         max_str = odd;
      if (even.length() > max_str.length())
         max_str = even;
   }
   return max_str;
}
int main()
{
   // code here
   string s, t, result;
   getline(cin, s);
   // getline(cin,t);
   // getline(cin,result);
   // string res = reverseWords(s);
   // bool res = validShuffleOrNot(s,t,result);
   string ans = longestPalindromicSub(s);
   // cout << res << endl;
   cout << ans << endl;

   return 0;
}