#include<bits/stdc++.h>
using namespace  std;
bool balancedBracket(string &s){
   stack<int> st;
   for(int i=0;i<s.size();i++){
      if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
      else{
         if(st.empty()) return false;
         char topChar = st.top();
         st.pop();
         if((s[i]==')' && topChar=='(') || (s[i]=='}' && topChar=='{') || (s[i]==']' && topChar=='['))
            continue;
         else 
            return false;
      }
   }
   return st.empty();
}
int main(){
   //code here
   int n;
   cin>>n;
   while(n--){
      string s;
      cin>>s;
      bool isTrue = balancedBracket(s);
      if(isTrue) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
   }

    return 0;
}