#include <bits/stdc++.h>
using namespace std;
void findSubsequenceStr(int indx,string &f,string &str,set<string> &subsequences){
   if(indx ==str.size()){
      subsequences.insert(f);
      return;
   }
   f = f+str[indx];
   findSubsequenceStr(indx+1,f,str,subsequences);
   f.pop_back();
   findSubsequenceStr(indx+1,f,str,subsequences);
}
int findCountStrSubsequence(string &str){
   set<string> subsequences;
   string f = "";
   findSubsequenceStr(0,f,str,subsequences);
   return subsequences.size();
}
string betterString(string &str1, string &str2)
{
   // code here
   if(str1.size()==1 && str2.size()==1) return str1;
   int str1Count = findCountStrSubsequence(str1);
   int str2Count = findCountStrSubsequence(str2);
   return str1Count>str2Count?str1:str2;
}
int main()
{
   // code here
   string str1,str2;
   getline(cin,str1);
   getline(cin,str2);
   string res = betterString(str1,str2);
   cout<<res<<endl;
   return 0;
}