#include<bits/stdc++.h>
using namespace  std;
bool checkOperand(char ch){
   if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
      return true;
   }else return false;
}
string preToInfix(string &str){
   stack<string> st;
   for(int i=0;i<str.size();i++){
      if(checkOperand(str[i])){
         st.push(string(1,str[i]));
      }
      else if(str[i]=='*' || str[i]=='/' || str[i]=='+' || str[i]=='-' || str[i]=='^'){
         string t1 = st.top();st.pop();
         string t2 = st.top();st.pop();
         string res = "("+t2+str[i]+t1+")";
         st.push(res);
      }
   }
   return st.top();
}
int main(){
   //code here
    string str;
    getline(cin,str);
    string ans = preToInfix(str);
    cout<<ans<<endl;

    return 0;
}