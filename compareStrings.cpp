#include<bits/stdc++.h>
using namespace  std;
bool backspaceStringCompare(string &S,string &T){
   stack<int> s1,s2;
    string str1,str2;

    for(int i=0;i<S.size();i++){
        if(S[i]=='#' && !s1.empty()){
            s1.pop();
        }
        else if(S[i]!='#'){
            s1.push(S[i]);
        }
    }
    for (int i = 0; i < T.size();i++){
        if(T[i] == '#' && !s2.empty()){
            s2.pop();
        }
        else if(T[i]!='#'){
            s2.push(T[i]);
        }
  }
  while(!s1.empty()){
      str1.push_back(s1.top());
      s1.pop();
  }
  while(!s2.empty()){
    str2.push_back(s2.top());
    s2.pop();
  }
  return str1 == str2;
}
int longestValidParenthesis(string s){
   stack<int> stt;
   int maxLen = INT_MIN;
   stt.push(-1);
   for(int i=0;i<s.size();i++){
      if(s[i]=='('){
         stt.push(i);
      }else{
         stt.pop();
         if(stt.empty()){
            stt.push(i);
         }
         int currLen = i-stt.top();
         maxLen = max(maxLen,currLen);
      }
   }
   return maxLen;
}
int main(){
   //code here
   //  string s,t;
   //  cin>>s>>t;
   string s;
   cin>>s;
   int res = longestValidParenthesis(s);
   cout<<res<<endl;
   //  bool res = backspaceStringCompare(s,t);
   //  if(res) cout<<"true";
   //  else cout<<"false";

    return 0;
}