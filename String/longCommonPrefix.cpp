#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &str)
{
   if(str.empty()) return "-1";
   sort(str.begin(), str.end());
   string first = str[0];
   string last = str[str.size()-1];
   int minLen = min(first.length(),last.length());
   string ans="";
   for(int i=0;i<minLen;++i){
      if(first[i]==last[i]){
         ans+=first[i];
      }else return ans;
   }
   return ans.empty()?"-1":ans;

   
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<string> str;
   for (int i = 0; i < n; i++)
   {
      string x;
      cin >> x;
      str.push_back(x);
   }
   string res = longestCommonPrefix(str);
    cout<<res<<endl;

   return 0;
}